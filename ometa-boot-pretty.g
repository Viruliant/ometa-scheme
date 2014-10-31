-- -*- text -*-
-- A copy of the automatically-produced ometa-boot.g, prettified by hand.

productions = production+;

production =
	&name:n
	production-part(n):x (token(";") production-part(n))*:xs token(";") spaces
		-> `(,n (or ,x ,@xs));

production-part :required-name =
	name:n -> (or (eq? n required-name) (error 'clause-name-mismatch))
	expr-seq:body ( token("=") expr:rhs -> `(seq ,body ,rhs)
		      |                     -> body);

expr-seq = (expr3)*:xs -> `(seq ,@xs);

expr3 = ( expr2:r ( token("*") -> `(many ,r)
		  | token("+") -> `(many1 ,r)
		  | 	       -> r)
	| token("@") -> `(position)):r
	( $: name:n -> `(bind ,n ,r)
	|    	    -> r);
expr3 = token(":") name:n -> `(bind ,n (anything));

expr2 = token("~") expr2:x -> `(not ,x);
expr2 = token("&") expr1:x -> `(follow ,x);
expr2 = expr1;

expr1 = token("<{") host-language-expression:s token("}>") -> `(sequence ,s);
expr1 = name:prod-exp apply-arguments:arg-exps -> `(apply ,prod-exp ,@arg-exps);
expr1 = token("->") host-language-expression:r -> `(action ,r);
expr1 = token("?") host-language-expression:r -> `(action (or ,r (error)));
expr1 = literal:x -> `(exactly ,x);
expr1 = token("_") -> `(anything);
expr1 = token("(") expr:x token(")") -> x;
expr1 = token("{") expr-seq:xs token("}") -> `(nest ,xs);

apply-arguments = $( ( token(")") -> '()
		     | scheme-term:a1 (token(",") scheme-term)*:aa token(")") -> (cons a1 aa));
apply-arguments = -> '();

literal = okeyword("nil", ());
literal = okeyword("true", #t);
literal = okeyword("false", #f);
literal = onumber;
literal = ostring(#\');
literal = token("$") ochar;
literal = token("#") (name | ostring(#\'):s -> (string->symbol s));

onumber = spaces (digit)+:ip
	  ( $. (digit)+:fp -> (string->number (string-append (list->string ip)
							     "." (list->string fp)))
	  |                -> (string->number (list->string ip)));

ostring ochar:quo =
	spaces
	ochar:s1 -> (or (eqv? s1 quo) (error 'expected 'string-open-quote))
	( ($\ ($\ | ochar:c -> (if (eqv? c quo) c (error 'expected 'escaped-quote))))
	| ochar:c -> (if (eqv? c quo) (error 'expected 'string-char) c))*:cs
	ochar:s2 -> (if (eqv? s2 quo)
		    	(list->string cs)
			(error 'expected 'string-close-quote));

ochar = :c -> (if (char? c) c (error 'expected 'char?));

expr = expr-seq:x (token("|") expr-seq)*:xs -> `(or ,x ,@xs);

okeyword :xs :val = spaces <{xs}> ~name-subsequent('(#\- #\? #\! #\* #\+ #\/ #\= #\: #\')) -> val;

token :xs = spaces <{xs}>;

name = generic-name('(), '(#\- #\_));

generic-name :initial-chars :subsequent-chars =
	spaces name-initial(initial-chars):x name-subsequent(subsequent-chars)*:xs
	       -> (string->symbol (list->string (cons x xs)));

name-initial :initial-chars =
	ochar:c -> (if (or (char-alphabetic? c)
		       	   (memv c initial-chars))
		       c
		       (error 'expected 'name-initial));

name-subsequent :subsequent-chars =
	ochar:x -> (if (or (char-alphabetic? x)
		       	   (char-numeric? x)
			   (memv x subsequent-chars))
		       x
		       (error 'expected 'name-subsequent));

digit = ochar:c -> (if (char-numeric? c) c (error 'expected 'char-numeric?));

spaces = (ochar:c -> (if (char-whitespace? c) c (error 'expected 'char-whitespace?)))+ spaces;
spaces = $- $- (:x -> (if (memv x '(#\return #\newline)) (error 'expected 'non-eol) x))* spaces;
spaces = -> #t;

host-language-expression = scheme-term;

scheme-term = scheme-atom;
scheme-term = scheme-quoted("'", 'quote);
scheme-term = scheme-quoted("`", 'quasiquote);
scheme-term = scheme-quoted(",", 'unquote);
scheme-term = scheme-quoted(",@", 'unquote-splicing);
scheme-term = token("(") scheme-sequence:xs token(")") -> xs;

scheme-quoted :quo :sym = spaces <{quo}> scheme-term:x -> `(,sym ,x);

scheme-atom = okeyword("#t", #t);
scheme-atom = okeyword("#f", #f);
scheme-atom = onumber;
scheme-atom = ostring(#\");
scheme-atom = token("#\\") ( token("return") ->#\return
	      		   | token("newline") ->#\newline
			   | ochar);
scheme-atom = scheme-symbol;
scheme-atom = ostring(#\|):s -> (string->symbol s);

scheme-symbol = generic-name('(#\? #\! #\* #\+ #\/ #\= #\: #\< #\>),
	      		     '(#\? #\! #\* #\+ #\/ #\= #\: #\< #\> #\' #\-));

scheme-sequence = scheme-term:a token(".") scheme-term:d -> (cons a d);
scheme-sequence = scheme-term:a scheme-sequence:d -> (cons a d);
scheme-sequence = -> '();
