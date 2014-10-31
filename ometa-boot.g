-- -*- text -*-

productions =
(production)+
;

production =
&name:n production-part(n):x (token(";") production-part(n))*:xs token(";") spaces ->(quasiquote ((unquote n) (or (unquote x) (unquote-splicing xs))))
;

production-part =
:required-name name:n ->(or (eq? n required-name) (error (quote clause-name-mismatch))) expr-seq:body (token("=") expr:rhs ->(quasiquote (seq (unquote body) (unquote rhs))) | ->body)
;

expr-seq =
(expr3)*:xs ->(quasiquote (seq (unquote-splicing xs)))
;

expr3 =
((expr2:r (token("*") ->(quasiquote (many (unquote r))) | token("+") ->(quasiquote (many1 (unquote r))) | ->r) | token("@") ->(quasiquote (position))):r ($: name:n ->(quasiquote (bind (unquote n) (unquote r))) | ->r) | token(":") name:n ->(quasiquote (bind (unquote n) (anything))))
;

expr2 =
(token("~") expr2:x ->(quasiquote (not (unquote x))) | token("&") expr1:x ->(quasiquote (follow (unquote x))) | expr1)
;

expr1 =
(token("<{") host-language-expression:s token("}>") ->(quasiquote (sequence (unquote s))) | name:prod-exp apply-arguments:arg-exps ->(quasiquote (apply (unquote prod-exp) (unquote-splicing arg-exps))) | token("->") host-language-expression:r ->(quasiquote (action (unquote r))) | token("?") host-language-expression:r ->(quasiquote (action (or (unquote r) (error)))) | literal:x ->(quasiquote (exactly (unquote x))) | token("_") ->(quasiquote (anything)) | token("(") expr:x token(")") ->x | token("{") expr-seq:xs token("}") ->(quasiquote (nest (unquote xs))))
;

apply-arguments =
($( (token(")") ->(quote ()) | scheme-term:a1 (token(",") scheme-term)*:aa token(")") ->(cons a1 aa)) | ->(quote ()))
;

literal =
(okeyword("nil", ()) | okeyword("true", #t) | okeyword("false", #f) | onumber | ostring(#\') | token("$") ochar | token("#") (name | ostring(#\'):s ->(string->symbol s)))
;

onumber =
spaces (digit)+:ip ($. (digit)+:fp ->(string->number (string-append (list->string ip) "." (list->string fp))) | ->(string->number (list->string ip)))
;

ostring =
ochar:quo spaces ochar:s1 ->(or (eqv? s1 quo) (error (quote expected) (quote string-open-quote))) (($\ ($\ | ochar:c ->(if (eqv? c quo) c (error (quote expected) (quote escaped-quote)))) | ochar:c ->(if (eqv? c quo) (error (quote expected) (quote string-char)) c)))*:cs ochar:s2 ->(if (eqv? s2 quo) (list->string cs) (error (quote expected) (quote string-close-quote)))
;

ochar =
:c ->(if (char? c) c (error (quote expected) (quote char?)))
;

expr =
expr-seq:x (token("|") expr-seq)*:xs ->(quasiquote (or (unquote x) (unquote-splicing xs)))
;

okeyword =
:xs :val spaces <{xs}> ~name-subsequent((quote (#\- #\? #\! #\* #\+ #\/ #\= #\: #\'))) ->val
;

token =
:xs spaces <{xs}>
;

name =
generic-name((quote ()), (quote (#\- #\_)))
;

generic-name =
:initial-chars :subsequent-chars spaces name-initial(initial-chars):x (name-subsequent(subsequent-chars))*:xs ->(string->symbol (list->string (cons x xs)))
;

name-initial =
:initial-chars ochar:c ->(if (or (char-alphabetic? c) (memv c initial-chars)) c (error (quote expected) (quote name-initial)))
;

name-subsequent =
:subsequent-chars ochar:x ->(if (or (char-alphabetic? x) (char-numeric? x) (memv x subsequent-chars)) x (error (quote expected) (quote name-subsequent)))
;

digit =
ochar:c ->(if (char-numeric? c) c (error (quote expected) (quote char-numeric?)))
;

spaces =
((ochar:c ->(if (char-whitespace? c) c (error (quote expected) (quote char-whitespace?))))+ spaces | $- $- (:x ->(if (memv x (quote (#\return #\newline))) (error (quote expected) (quote non-eol)) x))* spaces | ->#t)
;

host-language-expression =
scheme-term
;

scheme-term =
(scheme-atom | scheme-quoted("'", (quote quote)) | scheme-quoted("`", (quote quasiquote)) | scheme-quoted(",", (quote unquote)) | scheme-quoted(",@", (quote unquote-splicing)) | token("(") scheme-sequence:xs token(")") ->xs)
;

scheme-quoted =
:quo :sym spaces <{quo}> scheme-term:x ->(quasiquote ((unquote sym) (unquote x)))
;

scheme-atom =
(okeyword("#t", #t) | okeyword("#f", #f) | onumber | ostring(#\") | token("#\\") (token("return") ->#\return | token("newline") ->#\newline | ochar) | scheme-symbol | ostring(#\|):s ->(string->symbol s))
;

scheme-symbol =
generic-name((quote (#\? #\! #\* #\+ #\/ #\= #\: #\< #\>)), (quote (#\? #\! #\* #\+ #\/ #\= #\: #\< #\> #\' #\-)))
;

scheme-sequence =
(scheme-term:a token(".") scheme-term:d ->(cons a d) | scheme-term:a scheme-sequence:d ->(cons a d) | ->(quote ()))
;

