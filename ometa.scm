#lang scheme
;; OMeta Library
;;
;; Copyright (c) 2008 Tony Garnock-Jones <tonyg@kcbbs.gen.nz>
;; Copyright (c) 2008 LShift Ltd. <query@lshift.net>
;; 
;; Permission is hereby granted, free of charge, to any person
;; obtaining a copy of this software and associated documentation
;; files (the "Software"), to deal in the Software without
;; restriction, including without limitation the rights to use, copy,
;; modify, merge, publish, distribute, sublicense, and/or sell copies
;; of the Software, and to permit persons to whom the Software is
;; furnished to do so, subject to the following conditions:
;; 
;; The above copyright notice and this permission notice shall be
;; included in all copies or substantial portions of the Software.
;; 
;; THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
;; EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
;; MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
;; NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS
;; BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN
;; ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
;; CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
;; SOFTWARE.

;; Requires: SRFI-1, SRFI-9, SRFI-13, SRFI-69. See the documentation for more
;; details.

;; FIXME: move to wrapper
(require errortrace/errortrace-lib)
(require (except-in srfi/1 reverse! member map for-each assoc append!)
         srfi/9
         (except-in srfi/13 string-hash)
         srfi/69
         )

(provide (all-defined-out))

;; A parse position is a path. The tip of the path changes as we
;; consume tokens. Recursive parses push a new tip onto the path.
;; For files, a path tip is a (filename line column) triple.
;; Tips must be lists, strings, or numbers.
;; Lists have their most-significant element first.

(define *ometa-debug* (make-parameter #f))

;; false < numbers < strings < empty-list < list < true
(define (parse-position-type-index x)
  (cond
   ((not x) 0)
   ((number? x) 1)
   ((string? x) 2)
   ((null? x) 3)
   ((pair? x) 4)
   ((eq? x #t) 5)
   (else (error 'parse-position-type-index "Invalid parse-position ~v" x))))

(define parse-position-type-predicates
  (vector (lambda (a b) #f)
	  >
	  string>?
	  (lambda (a b) #f)
	  (lambda (a b)
	    (cond
	     ((parse-position>? (car a) (car b)) #t)
	     ((parse-position>? (car b) (car a)) #f)
	     (else (parse-position>? (cdr a) (cdr b)))))
	  (lambda (a b) #f)))

(define (parse-position>? a b)
  (let ((ta (parse-position-type-index a))
	(tb (parse-position-type-index b)))
    (cond
     ((> ta tb) #t)
     ((< ta tb) #f)
     (else ((vector-ref parse-position-type-predicates ta) a b)))))

(define (top-file-parse-position filename)
  (list filename 1 0))

(define (update-file-parse-position pos ch)
  (case ch
    ((#\return) (list (car pos) (cadr pos) 0))
    ((#\newline) (list (car pos) (+ (cadr pos) 1) 0))
    ((#\tab) (list (car pos) (cadr pos) (* (quotient (+ (caddr pos) 8) 8) 8)))
    (else (list (car pos) (cadr pos) (+ (caddr pos) 1)))))

(define (pretty-printN . xs)
  (pretty-print xs)
  (last xs))

;; A parse error is a pair of position-path and lset of error reports.
;; (<position> . (<error-report> ...))
(define (merge-parse-errors e1 e2)
  ;;(pretty-printN `(merge ,e1 ,e2)
  (cond
   ((not e1) e2)
   ((not e2) e1)
   (else (let ((p1 (car e1))
	       (p2 (car e2)))
	   (cond
	    ((or (parse-position>? p1 p2) (null? (cdr e2))) e1)
	    ((or (parse-position>? p2 p1) (null? (cdr e1))) e2)
	    (else (cons p1 (lset-union equal? (cdr e1) (cdr e2)))))))))
  ;;)

(define (merge-success prev-err ks)
  (lambda (sv new-env next err)
    (ks sv new-env next (merge-parse-errors err prev-err))))

(define (merge-failure prev-err kf)
  (lambda (err)
    (kf (merge-parse-errors err prev-err))))

;; Note that the argument pos is a parse position tip, not a position
;; path. It's wrapped in a list, making it into a position path,
;; before being placed in the error structure. See also
;; contextualize-parse-error.
(define (make-parse-error pos error-report)
  (cons (list pos) (list error-report)))

;; Note that the argument pos is a parse position tip, not a position
;; path. It is prepended to the position path in err, thereby placing
;; the err in the context of pos.
(define (contextualize-parse-error pos err)
  (and err (cons (cons pos (car err)) (cdr err))))

;; Input streams need to supply
;;  - head item
;;  - parse position tip (not a position path!)
;;  - tail stream
;;
;; Only the parse position tip gets passed on EOF.

(define (input-stream-cons pos item tail)
  (lambda (ks kf)
    (ks pos item tail)))

(define (input-stream-position stream)
  (stream (lambda (pos item tail) pos)
	  (lambda (pos) pos)))

(define (input-stream-append s1 s2)
  (lambda (ks kf)
    (s1 (lambda (pos item tail)
	  (ks pos item (input-stream-append tail s2)))
	(lambda (pos)
	  (s2 ks kf)))))

(define input-stream-constructors '())

(define (->input-stream-or-false x)
  (let search ((ctors input-stream-constructors))
    (cond
     ((null? ctors) #f)
     (((caar ctors) x) ((cdar ctors) x))
     (else (search (cdr ctors))))))

(define (->input-stream x)
  (or (->input-stream-or-false x)
      (error '->input-stream "Could not construct input stream from ~v" x)))

(define (input-stream-split-at-most input i k)
  (let loop ((acc '())
	     (i i)
	     (input input))
    (if (zero? i)
	(k (reverse acc) input)
	(input (lambda (pos item tail) (loop (cons item acc) (- i 1) tail))
	       (lambda (pos) (k (reverse acc) input))))))

(define (input-stream->list input)
  (input (lambda (pos item tail) (cons item (input-stream->list tail)))
	 (lambda (pos) '())))

(define (register-input-stream-constructor! predicate ctor)
  (set! input-stream-constructors
	(cons (cons predicate ctor)
	      input-stream-constructors)))

(register-input-stream-constructor!
 procedure? ;; covering input streams themselves
 (lambda (s)
   s))

(register-input-stream-constructor!
 list?
 (lambda (l)
   (let loop ((position 0)
	      (l l))
     (if (null? l)
	 (lambda (ks kf) (kf position))
	 (lambda (ks kf)
	   (ks position (car l) (loop (+ position 1) (cdr l))))))))

(register-input-stream-constructor!
 string?
 (lambda (s)
   (let ((len (string-length s)))
     (let loop ((index 0)
		(position (top-file-parse-position "<string>")))
       (if (= index len)
	   (lambda (ks kf) (kf position))
	   (lambda (ks kf)
	     (let ((ch (string-ref s index)))
	       (ks position
		   ch
		   (loop (+ index 1)
			 (update-file-parse-position position ch))))))))))

(register-input-stream-constructor!
 vector?
 (lambda (v)
   (let ((len (vector-length v)))
     (let loop ((index 0))
       (if (= index len)
           (lambda (ks kf) (kf index))
           (lambda (ks kf) (ks index (vector-ref v index) (loop (+ index 1)))))))))

(register-input-stream-constructor!
 input-port?
 (lambda (p)
   (make-port-input-stream "<unknown>" p)))

(define (make-port-input-stream filename p)
  (let loop ((position (top-file-parse-position filename)))
    (let ((ch (read-char p)))
      (if (eof-object? ch)
	  (lambda (ks kf) (kf position))
	  (let ((next (delay (loop (update-file-parse-position position ch)))))
	    (lambda (ks kf) (ks position ch (force next))))))))

(define (current-input-stream)
  (make-port-input-stream "<stdin>" (current-input-port)))

;; The result of parsing is either (semantic-value * new-env * next * error) or (error)

;; (apply production-name arg ...) ; both name and arg may be variables; args implicit - pushed on the input stream!
;; (or parser ...)
;; (exactly datum) ; nil true false <number> 'string' #symbol $c "sequence of chars"
;; (sequence)
;; ; () for grouping
;; (nest parser) ; nested parse! (sequence)
;; (not parser)
;; (follow parser)
;; (many parser)
;; (many1 parser)
;; (bind name parser)
;; (seq parser ...)
;; (anything)
;; (position)
;; (action meta-exp); -> exp, ?exp

(define-namespace-anchor ometa-namespace-anchor)
(define ometa-namespace-getter
  (make-parameter
   (lambda ()
     (namespace-anchor->namespace ometa-namespace-anchor))))

(define (interpret-ometa start rules input ks kf)
  (define (eval-host exp env k)
    (cond
     ((symbol? exp)
      (cond
       ((assq exp env) => (lambda (entry) (k (cadr entry) (cddr entry))))
       (else (error 'interpret-ometa "Unbound variable ~v" exp))))
     ((pair? exp)
      (case (car exp)
	((quote) (k #f (cadr exp)))
	(else
	 (error 'interpret-ometa "Applications not supported in eval-host: ~v" exp))))
     (else (k #f exp))))

  (define (push-actuals args env tail)
    (if (null? args)
	tail
	(eval-host (car args) env
		   (lambda (pos value)
		     (input-stream-cons pos value (push-actuals (cdr args) env tail))))))

  (define (collect-many exp env acc input err0 ks)
    (let collect ((acc acc)
		  (input input)
		  (prev-err err0))
      ;;(pretty-print `(collect-many ,(input-stream-position input) ,exp ,acc ,prev-err))
      (e exp env input
	 (lambda (sv new-env next err)
	   (collect (cons sv acc) next (merge-parse-errors err prev-err)))
	 (lambda (err)
	   ;;(pretty-print `(leaving ,exp ,acc ,prev-err and ,err))
	   (ks (reverse acc) env input (merge-parse-errors err prev-err))))))

  (define (nonshared-env env)
    (if (eq? env rules)
	'()
	(cons (car env) (nonshared-env (cdr env)))))

  (define (nonshared-env-values env)
    (if (eq? env rules)
	'()
	(cons (cddar env) (nonshared-env-values (cdr env)))))

  (define (shadowed-identifier s)
    (string->symbol (string-append "_" (symbol->string s))))

  (define (nonshared-env-names env)
    (let loop ((env env)
	       (acc '()))
      (cond
       ((eq? env rules) (reverse acc))
       ((memq (caar env) acc) (loop (cdr env) (cons (shadowed-identifier (caar env)) acc)))
       (else (loop (cdr env) (cons (caar env) acc))))))

  (define (compile-meta-exp exp names)
    (let ((success-sym (gensym)))
      (let ((source-form `(lambda (,success-sym error ,@names)
			    (,success-sym ,exp))))
	;;(pretty-print `((names ,names) (source-form ,source-form)))(newline)
	(eval source-form ((ometa-namespace-getter))))))

  (define memo-tab (make-hash-table equal?))
  (define action-tab (make-hash-table equal?))

  (define (e exp env input ks kf)
    (when (eq? (*ometa-debug*) #t)
	(pretty-print `(
			(exp ,exp)
			(env ,(nonshared-env env))
			(input ,(let ((l (input-stream-split-at-most input 32 (lambda (h t) h))))
				  (if (every char? l)
				      (list->string l)
				      l)))
			(pos ,(input-stream-position input))
			)))
    (case (car exp)
      ((apply)
       (when (*ometa-debug*)
	 (pretty-print `(apply (exp ,exp)
			       (pos ,(input-stream-position input)))))
       (let search-for-production ((production-exp (cadr exp)))
	 (eval-host production-exp env
	   (lambda (dummy-pos production)
	     (if (symbol? production)
		 (search-for-production production)
		 (let ((args (cddr exp)))
		   (if (null? args)
		       (let ((memo-probe (cons input production)))
			 (if (hash-table-exists? memo-tab memo-probe)
			     ((hash-table-ref memo-tab memo-probe)
			      (lambda (sv new-env next err) (ks sv env next err))
			      kf)
			     (e production rules input
				(lambda (sv new-env next err)
				  (hash-table-set! memo-tab memo-probe
						   (lambda (ks kf) (ks sv new-env next err)))
				  (ks sv env next err))
				(lambda (err)
				  (hash-table-set! memo-tab memo-probe
						   (lambda (ks kf) (kf err)))
				  (kf err)))))
		       (let ((extended-input (push-actuals args env input)))
			 (e production rules extended-input
			    (lambda (sv new-env next err)
			      (ks sv env next err))
			    kf)))))))))
      ((or)
       (if (null? (cdr exp))
	   (kf #f)
	   (let loop ((options (cdr exp))
		      (prev-err #f))
	     (cond
	      ((null? (cdr options))
	       (e (car options) env input
		  (merge-success prev-err ks)
		  (merge-failure prev-err kf)))
	      (else (e (car options) env input
		       (merge-success prev-err ks)
		       (lambda (err)
			 (loop (cdr options) (merge-parse-errors err prev-err)))))))))
      ((exactly)
       (let ((expected-value (cadr exp)))
	 (input (lambda (pos item tail)
		  (if (equal? item expected-value)
		      (ks item env tail #f)
		      (kf (make-parse-error pos `(expected ,expected-value)))))
		(lambda (pos)
		  (kf (make-parse-error pos `(expected ,expected-value)))))))
      ((sequence)
       (eval-host (cadr exp) env
	 (lambda (dummy-pos item0)
	   (let ((pos0 (input-stream-position input)))
	     (let loop ((xs (if (string? item0)
				(string->list item0)
				item0))
			(input input))
	       ;;(pretty-print `(in-sequence ,xs ,(list->string (input-stream->list input))))
	       (if (null? xs)
		   (ks item0 env input #f)
		   (input (lambda (pos item tail)
			    (if (equal? item (car xs))
				(loop (cdr xs) tail)
				(kf (make-parse-error pos0 `(expected ,item0)))))
			  (lambda (pos)
			    (kf (make-parse-error pos0 `(expected ,item0)))))))))))
      ((nest)
       (let ((context-position (input-stream-position input)))
	 (input (lambda (pos item tail)
		  (let ((stream (->input-stream-or-false item)))
		    (if stream
			(e (cadr exp) env stream
			   (lambda (sv new-env next err)
			     (ks sv new-env tail (contextualize-parse-error context-position err)))
			   (lambda (err)
			     (kf (contextualize-parse-error context-position err))))
			(kf #f))))
		(lambda (pos)
		  (kf #f)))))
      ((not)
       (e (cadr exp) env input
	  (lambda (sv new-env next err)
	    (kf (make-parse-error (input-stream-position input) `(unexpected ,(cadr exp)))))
	  (lambda (err)
	    (ks #t env input #f))))
      ((follow)
       (e (cadr exp) env input
	  (lambda (sv new-env next err)
	    (ks sv new-env input err))
	  kf))
      ((many)
       (collect-many (cadr exp) env '() input #f ks))
      ((many1)
       (e (cadr exp) env input
	  (lambda (sv new-env next err)
	    (collect-many (cadr exp) env (list sv) next err ks))
	  kf))
      ((bind)
       (e (caddr exp) env input
	  (lambda (sv new-env next err)
	    (ks sv
		(cons (cons (cadr exp) (cons (input-stream-position input) sv)) new-env)
		next
		err))
	  kf))
      ((seq)
       (if (null? (cdr exp))
	   (ks #f env input #f)
	   (let loop ((exps (cdr exp))
		      (env env)
		      (input input)
		      (prev-err #f))
	     ;;(pretty-print `(in-seq (exps ,exps) (env ,(nonshared-env env))))
	     (if (null? (cdr exps))
		 (e (car exps) env input
		    (merge-success prev-err ks)
		    (merge-failure prev-err kf))
		 (e (car exps) env input
		    (lambda (sv new-env next err)
		      (loop (cdr exps) new-env next (merge-parse-errors err prev-err)))
		    (merge-failure prev-err kf))))))
      ((anything)
       (input (lambda (pos item tail) (ks item env tail #f))
	      (lambda (pos) (kf #f))))
      ((position)
       (ks (input-stream-position input) env input #f))
      ((action)
       (let* ((names (nonshared-env-names env))
	      (probe (cons (cadr exp) names))
	      (fn (if (hash-table-exists? action-tab probe)
		      (hash-table-ref action-tab probe)
		      (let ((v (compile-meta-exp (cadr exp) names)))
			(hash-table-set! action-tab probe v)
			v)))
	      (escape '*)
	      (escaped (call-with-current-continuation
			(lambda (set-escaped!)
			  (set! escape (lambda error-report
					 (set-escaped! error-report)))
			  #f))))
	 (if escaped
	     (kf (if (null? escaped)
		     #f
		     (make-parse-error (input-stream-position input) escaped)))
	     (apply fn
		    (lambda (sv) (ks sv env input #f))
		    escape
		    (nonshared-env-values env)))))
      (else (error 'interpret-ometa "Bad OMeta AST: ~v" exp))))

  (e `(apply ,start) rules input
     ks
     kf))

(define (grammar->env g)
  (map (lambda (raw-production)
	 (cons (car raw-production)
	       (cons #f ;; parse-position
		     (cadr raw-production))))
       g))

(define meta-ometa
  '(
    (productions (many1 (apply production)))

    (production (seq (bind n (follow (apply name)))
		     (bind x (apply production-part n))
		     (bind xs (many (seq (apply token ";")
					 (apply production-part n))))
		     (apply token ";")
		     (apply spaces)
		     (action `(,n (or ,x ,@xs)))))

    (production-part (seq (bind required-name (anything))
			  ;;
			  (bind n (apply name))
			  (action (or (eq? n required-name)
				      (error 'clause-name-mismatch)))
			  (bind body (apply expr-seq))
			  (or (seq (apply token "=")
				   (bind rhs (apply expr))
				   (action `(seq ,body ,rhs)))
			      (action body))))

    (expr-seq (seq (bind xs (many (apply expr3)))
		   (action `(seq ,@xs))))

    (expr3 (or (seq (bind r (or (seq (bind r (apply expr2))
				     (or (seq (apply token "*") (action `(many ,r)))
					 (seq (apply token "+") (action `(many1 ,r)))
					 (action r)))
				(seq (apply token "@") (action `(position)))))
		    (or (seq (exactly #\:) (bind n (apply name))
			     (action `(bind ,n ,r)))
			(action r)))
	       (seq (apply token ":") (bind n (apply name))
		    (action `(bind ,n (anything))))))

    (expr2 (or (seq (apply token "~") (bind x (apply expr2))
		    (action `(not ,x)))
	       (seq (apply token "&") (bind x (apply expr1))
		    (action `(follow ,x)))
	       (apply expr1)))

    (expr1 (or (seq (apply token "<{")
		    (bind s (apply host-language-expression))
		    (apply token "}>")
		    (action `(sequence ,s)))
	       (seq (bind prod-exp (apply name))
		    (bind arg-exps (apply apply-arguments))
		    (action `(apply ,prod-exp ,@arg-exps)))
	       (seq (apply token "->") (bind r (apply host-language-expression))
		    (action `(action ,r)))
	       (seq (apply token "?") (bind r (apply host-language-expression))
		    (action `(action (or ,r (error)))))
	       (seq (bind x (apply literal))
		    (action `(exactly ,x)))
	       (seq (apply token "_") (action `(anything)))
	       (seq (apply token "(") (bind x (apply expr)) (apply token ")")
		    (action x))
	       (seq (apply token "{") (bind xs (apply expr-seq)) (apply token "}")
		    (action `(nest ,xs)))))

    (apply-arguments (or (seq (exactly #\( ) ;; no space permitted before open-paren!
			      (or (seq (apply token ")")
				       (action '()))
				  (seq (bind a1 (apply scheme-term))
				       (bind aa (many (seq (apply token ",")
							   (apply scheme-term))))
				       (apply token ")")
				       (action (cons a1 aa)))))
			 (action '())))

    (literal (or (apply okeyword "nil" ())
		 (apply okeyword "true" #t)
		 (apply okeyword "false" #f)
		 (apply onumber)
		 (apply ostring #\')
		 (seq (apply token "$") (apply ochar))
		 (seq (apply token "#") (or (apply name)
					    (seq (bind s (apply ostring #\'))
						 (action (string->symbol s)))))))

    (onumber (seq (apply spaces) (bind ip (many1 (apply digit)))
		  (or (seq (exactly #\.) (bind fp (many1 (apply digit)))
			   (action (string->number (string-append (list->string ip)
								  "."
								  (list->string fp)))))
		      (action (string->number (list->string ip))))))

    (ostring (seq (bind quo (apply ochar))
		  ;;
		  (apply spaces)
		  (bind s1 (apply ochar))
		  (action (or (eqv? s1 quo) (error 'expected 'string-open-quote)))
		  (bind cs (many (or (seq (exactly #\\)
					  (or (exactly #\\)
					      (seq (bind c (apply ochar))
						   (action (if (eqv? c quo)
							       c
							       (error 'expected
								      'escaped-quote))))))
				     (seq (bind c (apply ochar))
					  (action (if (eqv? c quo)
						      (error 'expected 'string-char)
						      c))))))
		  (bind s2 (apply ochar))
		  (action (if (eqv? s2 quo)
			      (list->string cs)
			      (error 'expected 'string-close-quote)))))

    (ochar (seq (bind c (anything))
		(action (if (char? c)
			    c
			    (error 'expected 'char?)))))

    (expr (seq (bind x (apply expr-seq))
	       (bind xs (many (seq (apply token "|") (apply expr-seq))))
	       (action `(or ,x ,@xs))))

    (okeyword (seq (bind xs (anything))
		   (bind val (anything))
		   ;;
		   (apply spaces) (sequence xs)
		   (not (apply name-subsequent '(#\- #\? #\! #\* #\+ #\/ #\= #\: #\')))
		   (action val)))

    (token (seq (bind xs (anything))
		;;
		(apply spaces) (sequence xs)))

    (name (apply generic-name
		 '()
		 '(#\- #\_)))

    (generic-name (seq (bind initial-chars (anything))
		       (bind subsequent-chars (anything))
		       ;;
		       (apply spaces)
		       (bind x (apply name-initial initial-chars))
		       (bind xs (many (apply name-subsequent subsequent-chars)))
		       (action (string->symbol (list->string (cons x xs))))))

    (name-initial (seq (bind initial-chars (anything))
		       ;;
		       (bind c (apply ochar))
		       (action (if (or (char-alphabetic? c)
				       (memv c initial-chars))
				   c
				   (error 'expected 'name-initial)))))

    (name-subsequent (seq (bind subsequent-chars (anything))
			  ;;
			  (bind x (apply ochar))
			  (action (if (or (char-alphabetic? x)
					  (char-numeric? x)
					  (memv x subsequent-chars))
				      x
				      (error 'expected 'name-subsequent)))))

    (digit (seq (bind c (apply ochar))
		(action (if (char-numeric? c)
			    c
			    (error 'expected 'char-numeric?)))))

    (spaces (or (seq (many1 (seq (bind c (apply ochar))
				 (action (if (char-whitespace? c)
					     c
					     (error 'expected 'char-whitespace?)))))
		     (apply spaces))
		(seq (exactly #\-) (exactly #\-)
		     (many (seq (bind x (anything))
				(action (if (memv x '(#\return #\newline))
					    (error 'expected 'non-eol)
					    x))))
		     (apply spaces))
		(action #t)))

    (host-language-expression (apply scheme-term))

    (scheme-term (or (apply scheme-atom)
		     (apply scheme-quoted "'" 'quote)
		     (apply scheme-quoted "`" 'quasiquote)
		     (apply scheme-quoted "," 'unquote)
		     (apply scheme-quoted ",@" 'unquote-splicing)
		     (seq (apply token "(")
			  (bind xs (apply scheme-sequence))
			  (apply token ")")
			  (action xs))))

    (scheme-quoted (seq (bind quo (anything))
			(bind sym (anything))
			;;
			(apply spaces)
			(sequence quo)
			(bind x (apply scheme-term))
			(action `(,sym ,x))))

    (scheme-atom (or (apply okeyword "#t" #t)
		     (apply okeyword "#f" #f)
		     (apply onumber)
		     (apply ostring #\")
		     (seq (apply token "#\\")
			  (or (seq (apply token "return") (action #\return))
			      (seq (apply token "newline") (action #\newline))
			      (apply ochar)))
		     (apply scheme-symbol)
		     (seq (bind s (apply ostring #\|))
			  (action (string->symbol s)))))

    (scheme-symbol (apply generic-name
			  '(#\? #\! #\* #\+ #\/ #\= #\: #\< #\>)
			  '(#\? #\! #\* #\+ #\/ #\= #\: #\< #\> #\' #\-)))

    (scheme-sequence (or (seq (bind a (apply scheme-term))
			      (apply token ".")
			      (bind d (apply scheme-term))
			      (action (cons a d)))
			 (seq (bind a (apply scheme-term))
			      (bind d (apply scheme-sequence))
			      (action (cons a d)))
			 (action '())))
    ))

(define (serialize-ometa-ast ast)
  (define (emit arg)
    (cond
     ((null? arg))
     ((pair? arg) (emit (car arg)) (emit (cdr arg)))
     (else (display arg))))
  (define (xi sep fn args)
    (if (null? args)
	'()
	(let loop ((args args))
	  (if (null? (cdr args))
	      (fn (car args))
	      (begin (list (fn (car args)) sep (loop (cdr args))))))))
  (define (xii op sep fn args cl)
    (list op (xi sep fn args) cl))
  (define (q qch str)
    (list qch (map (lambda (c) (if (eqv? c qch) (list #\\ qch) c)) (string->list str)) qch))
  (define (object->external-representation o)
    (let ((s (open-output-string)))
      (write o s)
      (get-output-string s)))
  (define (serialize-exp exp)
    (case (car exp)
      ((apply) (list (cadr exp)
		     (if (null? (cddr exp))
			 '()
			 (xii "(" ", " object->external-representation (cddr exp) ")"))))
      ((or) (xii "(" " | " serialize-exp (cdr exp) ")"))
      ((exactly) (let ((ev (cadr exp)))
		   (cond
		    ((null? ev) "nil")
		    ((eq? #t ev) "true")
		    ((eq? #f ev) "false")
		    ((number? ev) (number->string ev))
		    ((string? ev) (q #\' ev))
		    ((char? ev) (list "$" ev))
		    ((symbol? ev) (let ((s (symbol->string ev)))
				    (list "#" (if (memv #\' (string->list s))
						  (q #\' s)
						  s))))
		    (else (error 'serialize-ometa-ast "Invalid literal in (exactly): ~v" ev)))))
      ((sequence) (list "<{"(object->external-representation (cadr exp))"}>"))
      ((nest) (list "{"(serialize-exp (cadr exp))"}"))
      ((not) (list "~"(serialize-exp (cadr exp))))
      ((follow) (list "&"(serialize-exp (cadr exp))))
      ((many) (list "("(serialize-exp (cadr exp))")*"))
      ((many1) (list "("(serialize-exp (cadr exp))")+"))
      ((bind) (if (equal? (caddr exp) '(anything))
		  (list ":"(cadr exp))
		  (list (serialize-exp (caddr exp))":"(cadr exp))))
      ((seq) (xi " " serialize-exp (cdr exp)))
      ((anything) "_")
      ((action) (list "->"(object->external-representation (cadr exp))))
      (else (error 'serialize-ometa-ast "Bad AST in serialize: ~v" exp))))
  (define (serialize-production production)
    (list (car production)" =\n"
	  (serialize-exp (cadr production))
	  "\n;\n\n"))
  (emit (map serialize-production ast)))

(define (format-ometa-error err)
  (if err
      (let ((s (open-output-string)))
	(display "Parse error at position " s)
	(write (car err) s)
	(newline s)
	(display "Error messages:" s)
	(newline s)
	(for-each (lambda (msg)
		    (display " - " s)
		    (write msg s)
		    (newline s))
		  (cdr err))
	(get-output-string s))
      "No error"))

(define (report-ometa-error err)
  (display (format-ometa-error err))
  (newline)
  (error 'ometa-parse-error))

(define (parse-ometa input . maybe-error-handler)
  (let ((error-handler (if (null? maybe-error-handler)
			   report-ometa-error
			   (car maybe-error-handler))))
    (interpret-ometa 'productions (grammar->env meta-ometa) (->input-stream input)
		     (lambda (sv new-env tail err)
		       (if (null? (input-stream->list tail))
			   sv
			   (error-handler err)))
		     error-handler)))

(define (parse-ometa-file filename . maybe-error-handler)
  (call-with-input-file filename
    (lambda (port)
      (apply parse-ometa (make-port-input-stream filename port) maybe-error-handler))))

(define ometa-library-path (make-parameter #f))

(define opt-ometa
  (let ((cache #f))
    (lambda ()
      (when (not cache)
	(set! cache
	      (let ((opt-ometa-unoptimised
		     (parse-ometa-file (path->string (build-path (or (ometa-library-path)
								     (current-directory))
								 "ometa-opt.g")))))
		(interpret-ometa 'opt-grammar
				 (grammar->env opt-ometa-unoptimised)
				 (->input-stream opt-ometa-unoptimised)
				 (lambda (sv new-env tail err) sv)
				 (lambda (err) (error 'opt-ometa
						      "Problem optimising optimiser: ~v" err))))))
      cache)))
(define (opt g)
  (interpret-ometa 'opt-grammar (grammar->env (opt-ometa)) (->input-stream g)
		   (lambda (sv new-env tail err)
;; 		     (pretty-print `(success (sv ,sv)
;; 					     (pos ,(input-stream-position tail))
;; 					     (tail ,(input-stream->list tail))
;; 					     (err ,err)))
		     sv)
		   (lambda (err)
		     (pretty-print `(failure ,err))
		     err)))

(define (merge-ometa base extension)
  (let* ((merged-productions (map (lambda (base-production)
				    (cond
				     ((assq (car base-production) extension) =>
				      (lambda (extension-production)
					`(,(car base-production) (or ,(cadr extension-production)
								     ,(cadr base-production)))))
				     (else
				      base-production)))
				  base))
	 (missing-productions (fold (lambda (extension-production acc)
				      (cond
				       ((assq (car extension-production) merged-productions)
					acc)
				       (else
					(cons extension-production acc))))
				    '()
				    extension)))
    (opt (append missing-productions merged-productions))))

(define (load-ometa filename . maybe-ometa-parser)
  (let ((grammar (opt ((if (null? maybe-ometa-parser)
			   parse-ometa-file
			   (car maybe-ometa-parser)) filename))))
    (lambda (start-symbol stream ks kf)
      (simple-ometa-driver grammar start-symbol stream ks kf))))

(define (simple-ometa-driver grammar start-symbol stream ks kf)
  (interpret-ometa start-symbol (grammar->env grammar) (->input-stream stream)
		   (lambda (sv new-env tail err)
		     (ks sv tail err))
		   (lambda (err)
		     ;;(pretty-print `(failure ,err))
		     (kf err))))

(define (boot)
  (define (d x)
    (with-output-to-file x
      (lambda ()
	(display "-- -*- text -*-")
	(newline)
	(newline)
	(serialize-ometa-ast meta-ometa))))
  (d "m0.g")
  (set! meta-ometa (opt (parse-ometa-file "m0.g")))
  (d "m1.g")
  (set! meta-ometa (opt (parse-ometa-file "m1.g")))
  (d "m2.g")
  (set! meta-ometa (opt (parse-ometa-file "m2.g"))))

;;; Local Variables:
;;; eval: (put 'eval-host 'scheme-indent-function 2)
;;; End:
