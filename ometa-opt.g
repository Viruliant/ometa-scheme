-- -*- text -*-

opt-grammar = {opt-production}*;

end = ~_ ;

opt-production = :n opt:o -> `(,n ,o);

opt = {:t t};

opt-inside :t =
  {:t1 ->(or (eq? t t1) (error 'expected t)) opt-inside(t):xs} opt-inside(t):ys -> (append xs ys)
| opt:x							       opt-inside(t):xs -> (cons x xs)
|										-> '()
;

apply :prod (_*):args -> `(apply ,prod ,@args);

or opt:o end -> o;
or opt-inside('or):os -> (if (= (length os) 1) (car os) `(or ,@os));

seq opt:o end -> o;
seq opt-inside('seq):os -> (if (= (length os) 1) (car os) `(seq ,@os));

nest opt:m end -> `(nest ,m);
not opt:m end -> `(not ,m);
follow opt:m end -> `(follow ,m);
many opt:m end -> `(many ,m);
many1 opt:m end -> `(many1 ,m);
anything end -> `(anything);
bind :n opt:m -> `(bind ,n ,m);
action :exp -> `(action ,exp);
exactly :datum -> `(exactly ,datum);
sequence :exp -> `(sequence ,exp);
position -> `(position);
