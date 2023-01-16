This repository is to serve as a backup if for any reason
https://www.piumarta.com/pepsi/idst-20070830/ goes down.

This project is one of the 2 cited working implementations of [OMeta: an Object-Oriented Language for Pattern Matching Alessandro Warth, Ian Piumarta](http://www.vpri.org/pdf/tr2007003_ometa.pdf)

Ian Piumarta also did another presentation "[Building Your Own Dynamic Language](https://youtu.be/cn7kTPbW6QQ)" here are the slides for that -> [slides](https://www.piumarta.com/papers/EE380-2007-slides.pdf)

# Meta expression
A META expression will be introduced by an active 'escape' character buried in a Coke program. This character will invoke a meta sequence reader. -- [Customising the Coke scanner]()

    expression  	meaning
    { e... }	any one of the elements e...
    [ e... ]	all of the elements e... in order
    $ e	any number (zero or more) of e
    @ ( p v )	anything satisfying predicate p
    that will be bound to variable v
    ! p	the predicate p (any Coke expression)

# Domain-Specific Languages (OMeta) - 34:20 - Alessandro Warth

OMeta: an Object-Oriented Language for Pattern Matching ∗
Alessandro Warth, Ian Piumarta

2 implementations available at http://www.cs.ucla.edu/∼awarth/ometa/


## Introduction
[Youtube 34:20](https://youtu.be/GSeY1oD7dN0?t=2060)
Hi so I'm Alex and I'm a programmer and I always like having ideas 
about things that could help out programmers and stuff but one thing 
that really gets to me well is that you can't just keep having ideas 
and just sort of experiment with the ideas quickly because you have 
to prototype a programming language when you have these ideas and 
that usually takes a lot of time there's a lot of effort that goes 
into it and programming language designers like me we tend to get 
lethargic you know and feel like oh man.

[35:44](https://youtu.be/GSeY1oD7dN0?t=2144)
Okay I have a couple of ideas that might work but I really have to be 
selective because I don't have infinite time to implement all these 
things and so um I was so upset about this so I called my mom and she 
said she said alex I'm a dermatologist what do you want me to do so 
that didn't help very much but but luckily uh alan pointed me to some 
papers uh from the 1960s and 70s that were really interesting and one 
of them uh was a paper uh by val shorey who was a guy at UCLA in the 
60s and uh it was about a language called meta two that he developed 
and it was a compiler generator kind of thing uh it was very similar 
to parsing expression grammars uh that are sort of in vogue now and 
uh but this was in the 60s and uh the computing resources that 
valsharry had were very limited and so uh and and yet somehow he was 
able to come up with this little language that was fairly easy to 
learn and uh allowed him to implement a pretty interesting subset of 
algol in like a page of code and the language itself the the meta 
language could be compiled by itself in about a a page of code as 
well.

[37:16](https://youtu.be/GSeY1oD7dN0?t=2235)
So i looked at that 
stuff and i thought wow i have to implement this on my own to try 
this out you know the bootstrapping was beautiful and everything so 
once i did that which only took a day or so i felt really empowered 
because i had been using these uh these larger frameworks like 
polyglot for extending java and i had written things by hand quite a 
few times to know that you know it was very costly and so when i 
started doing this thing with meta too i got excited and i started 
extending it to kind of catch up with the times because for instance 
uh the original thing didn't support backtracking uh because 
resources were limited and by now you can do as much backtracking as 
you want and it's not a big deal so anyway i had some ideas about 
extensions that i could have on this thing and this this was kind of 
the the birth of my language called ometa which we have used to 
implement several programming languages in this project that we're 
experimenting with and the goal of this thing is to minimize the 
amount of time that it takes to go from idea uh to a working 
prototype and i'm not so much i'm not so worried about the efficiency 
of the prototype or whatever as long as i can get something that runs 
efficiently enough for me to try out the idea and make sure that it's 
that it's uh you know an interesting thing to pursue further and so 
on but we've had uh pretty good luck with that kind of thing and 
things that we've made with it have been fairly efficient so far

[38:46](https://youtu.be/GSeY1oD7dN0?t=2326)
so 
what you're looking at right now is kind of like a small talk 
workspace interface that lets you type in some code and evaluate it 
on the fly and this is running inside the browser i have several 
ometa implementations this particular one uses javascript as the 
target language as the assembly language underneath and so in this 
web browser i can just type in a bunch of code like well even any 
javascript expression like that i can evaluate on the fly but uh 
that's not very interesting right because i as a language guy i want 
control over the language that i'm using and so the stuff that you 
tell it to evaluate is not necessarily the stuff that gets evaluated 
there's a level of there's an interaction here in this function oops 
called translate code that gets called with the string that you want 
to evaluate and is supposed to return the the thing that you pass to 
the valve function in javascript so it doesn't matter what it says 
right now but the cool thing about this is it lets you replace the 
programming language that's been that's being used uh in this 
interface very easily and of course it's very self-serving because 
omada is sort of the ideal language as far as i'm concerned to write 
something like translate code i'm very modest today i guess so um 
let's see here i don't know why i can't see well it's fairly big oh i 
know what's going on hang on technical difficulties okay

[40:26](https://youtu.be/GSeY1oD7dN0?t=2426)
instead of going over the language and stuff i'm just going to say a 
few words about it and then i'm going to show you a bunch of examples 
and end up with dan's nile translator so the the main idea in the 
language is that pattern matching is good for most things that you 
care about in writing a translator for instance uh if all you care 
about is lexical analysis you can pattern match on a stream of 
characters and produce a stream of tokens similarly to write a parser 
you can pattern match on a stream of tokens to produce parse trees 
and then code generation at least naive code generation can be done 
by pattern matching on a parse tree to output some code and so on 
even transformations on parse trees and optimizations can be done in 
the same way and so let's start off with something fairly standard so 
a little while ago i sat down with a friend of mine and i wrote a 
library in javascript that's about 70 lines of code that implements 
the semantics of prologue including you know unification backtracking 
all that stuff and that's what's being loaded on the top of the page 
the thing that you see right here is a grammar written in ometa that 
teaches the browser how to understand prolog syntax it doesn't 
include things like the special list syntax in prolog but that 
doesn't matter anyway because it's just syntactic sugar so the the 
important stuff is there and it's fairly easy to grasp and gist

[42:00](https://youtu.be/GSeY1oD7dN0?t=2520)
and 
so on so i'm gonna load this stuff and okay now down here i can tell 
my prologue translator to answer certain prologue queries given a few 
facts and rules just like you would do in a real prologue interpreter 
and so in this first example i'm asking for all the natural numbers 
given that 0 is a natural number and the successor of x is a natural 
number if x is a natural number and so if i select this stuff and 
tell it to execute it's saying that 0 is a natural number sorry it's 
kind of small 1 is a natural number 2 is a natural number and so on 
it'll go on forever until i tell it i'm done and then this next 
example should be very familiar it's it's the usual thing that 
everyone does in prologue in their first couple of sessions right 
it's a it's an all male in child world so i'm asking for all the 
grandfather and grandchild relationships given that you know abe is a 
homer's father homer is lisa's father homer's bart's father and homie 
homer is maggie's uh father and then there's the rule for grandfather 
in there which yeah it doesn't include women i guess i'm not pc or 
something so uh when i say that you get the right answers it 
enumerates all the three relationships that you care about


[43:46](https://youtu.be/GSeY1oD7dN0?t=2626)
so uh 
quickly i'm gonna show you a couple more of these before i move on to 
the meaty stuff where is that by the way this is a wiki uh also and 
so anyone who's interested in this stuff can just open up this 
webpage on their browser without downloading anything and see these 
projects try them out and make their own project save them and so on 
so okay on this page uh what i have it's roughly a page of code here 
this is a logo syntax and on the left hand side you see sort of the 
bnf style rules to describe the logo syntax using left recursion and 
stuff uh it's fairly readable and on the right hand side there's some 
javascript code that's being output by the semantic actions and and 
then this is the neat part after i've defined the language and 
there's a little bit of runtime support above the grammar i can 
redefine translate code to be a function that takes in the code that 
you tell it to evaluate and then passes to smiley my turtle the code 
to evaluate and and doesn't return any useful value undefined by the 
way i'm returning the undefined string because when javascript tries 
to evaluate the undefined string it's not going to do much so if i 
select all the stuff and tell it to evaluate quickly this added uh my 
code added a you know dynamically added a canvas elements to this 
page and then down here so it it's also switched the language that's 
understood by this browser by this uh workspace so i can teach it to 
do a spiral which is code that i actually took from the wikipedia 
page on pro on on logo and then if i tell it to draw a spiral and i 
can oh that was too quick and i messed up but i can draw another one 
well hopefully i don't think i'm cheating but it actually draws in 
real time and it looks really cute

## override javascript with identity transformation 
[46:06](https://youtu.be/GSeY1oD7dN0?t=2766)
so anyway now i'm going to show 
you some more interesting examples first thing i want to show you is 
that there's a little javascript compiler it's not really a compiler 
that's a bit of a misnomer what this is in this case by the way i 
have implemented a very nearly complete subset of javascript it's 
about like maybe 90 or 95 of the language using omada and i have a a 
translator that takes the javascript program and outputs some small 
talk and it works on top of squeak so that's pretty neat to play with 
but i don't have time to show that today uh and i have a couple other 
back-ends for that but in this case what i have is a javascript 
parser written in ometa that's about 120-140 lines of code i don't 
remember exactly what it is and then after that i have a translator 
that pattern matches on the parse trees that i generate and outputs 
the javascript code again so it's sort of the identity transformation 
on javascript which on its own is not very interesting but the neat 
thing about it is that once you have something like that you can 
easily because ometa is object oriented you can inherit from these 
grammars and override certain rules for instance if you want to add a 
new kind of statement you override the statement rule and uh and add 
some new construct and stuff so i'm gonna skip over that example but 
you you guys get the idea so far right okay

## Ometa is implemented in itself
[47:33](https://youtu.be/GSeY1oD7dN0?t=2853)
uh of course ometa is 
implemented in itself oops so uh in a very similar style to that 
javascript translator that i just showed you so this is the parser 
for ometa and underneath is the code generator which just translates 
the parse trees to javascript and i have a little bit of a library 
that i wrote that's maybe something like 50 lines of code or whatever 
that supports the semantics of omada in javascript and that's the way 
i bootstrap ometa on a new platform usually just implement a very 
minimal set of semantics as a library in that host language and then 
i do the parsing and code generation in ometa but one interesting 
thing here is that you don't have to do this you know very direct 
two-step process uh you can do some more interesting things with it 
so for instance the ometa translator is just taking a parse tree and 
outputting the javascript but my parser is not extremely smart for 
instance if you if you have nested or expressions you know while 
you're doing your pattern matching as you often do if i use 
parentheses you know i say x or y or z that's going to generate two 
or operations you know and the or operation no meta has to remember 
the position that you're at so that it can backtrack properly and so 
on and uh that's sort of wasteful so one thing that i did that was 
very straightforward was i implemented an optimization an 
optimization framework for ometa parse trees you know meta itself 
after i had the stuff working and so what you see on top here is a 
grammar that pattern matches on a parse tree for omega and by looking 
at this you can see how little you have to implement in order to have 
a language like ometa it's very similar to brian ford's pegs you know 
you only have or and cleaning star cleaning plus this is assignment 
which is used for binding uh expressions to names uh there's a not 
operation look ahead and so on so it's fairly straightforward anyway 
this is kind of like a visitor for ometa parse trees and on its own 
it's not very useful but then down here what i'm doing is i'm is i'm 
inheriting this visitor and overriding the and and or rules so that 
when i have nesting you know if i have an and that has an and as an 
argument i can pull out the parts of that and into the outer end and 
the semantics is going to be the same except it's going to be more 
efficient because i only have uh you know to implement that one 
operation and uh and when i implemented this the the omega js 
implementation became i think 30 faster which was pretty neat for 
very minimal effort 


## MetaToo
[50:37](https://youtu.be/GSeY1oD7dN0?t=3037)
uh so anyway i think oh yeah and the last thing i 
wanted to show you here before i show the dan stuff is uh so if you 
if you end up taking the time to take to look at this stuff online i 
encourage you to look at this project it's called meta2to which is a 
pun on you know the meta2 which and the roman numeral 2 that i told 
you about before and what this is is a language that's very close to 
ometa implemented entirely in this little project and so at first 
this this javascript object that you see up here is a is the library 
object that implements all of the semantics that you need for doing 
the parsing and pattern matching and then down here what i have is 
the parser for this language written in omata and then i have a 
couple of examples you know with with arithmetic expressions and so 
on but then of course that is not sufficient to do bootstrapping what 
you really need to do is once you have the the ometa like language 
working you want to write that you want to implement that guy in 
itself which is what i do down here and you can see it's a little bit 
uglier than omega particularly because the semantic actions have to 
be enclosed in these funny characters and so on but i did that so 
that i wouldn't have to implement a javascript parser as part of this 
thing right so i can just blindly consume the javascript and output 
it in the translated code uh anyway that's the implementation of that 
and you can compile the compiler with the original compiler that i 
wrote with omeda and it works and then the thing that really tests it 
later on is if you take the the version of the compiler that was 
generated from the code up here by using the ometa you know compiler 
uh if you take that and and compile it with itself and replace the 
thing you're using with that result and it still works down here you 
know you're you're good and that kind of works so it's a it's a neat 
little example of bootstrapping um if you want to take a look at that 
later on

## Foreign Rule Invocation ??
[53:04](https://youtu.be/GSeY1oD7dN0?t=3184)
so i think oh yeah one last thing that i want to show here 
and take a quick look at this javascript doesn't have multi-line 
string literals right but if you look at this i'm actually using one 
right here it looks very python-esque and the reason why i can do 
that is because you know this translate code thing my javascript 
doesn't have to be javascript right i have that intermediate thing 
the javascript parser and translator that i showed you before and i 
can easily inherit from that and add new kinds of things so that was 
very straightforward and the the other neat thing about having things 
uh having these languages implemented in ometa is that there's a 
thing called foreign rule invocation that allows a grammar to lend 
its input stream to another grammar temporarily and it's an it's an 
alternative to inheritance for instance you may have noticed that the 
language that i'm using in this workspace is not just javascript and 
it's not just ometa it's kind of a mashup of these two languages and 
if you wanted to implement that with single inheritance you would 
have to inherit from one of these translators and then implement the 
functionality of the other translator which would be uh very annoying 
to have to do uh and multiple inheritance is clearly a bad idea i'm 
not going to go into that because of all the you know complications 
and and so on and so with foreign rule invocation i can just have one 
grammar that doesn't inherit from either if i don't want to and just 
says try parsing my input as an ometa grammar and if that doesn't 
work try parsing my input as a javascript statement or expression or 
whatever sorry punch line yes okay

## nile language
[54:39](https://youtu.be/GSeY1oD7dN0?t=3279)
so um what you're looking at here 
is a part of my translator for the nile language that dan was talking 
about so the stuff on top implements is a grammar that on its own 
implements the offside rule you know indentation as block structure 
that you see in python and haskell and so on the neat thing about 
that is that that's modularized away from whatever language that 
you're implementing so all the stuff like uh keeping track of a stack 
of indentation levels and so on that can be done in that one grammar 
and my my nile parser which is down here also written in omega just 
inherits from that guy and can just uh say you know i i want to uh i 
want to indent i don't know let's anyway there's there's there's a 
bunch of indentation code ah here we go so i want to i want to tab 
over here and then there are these funny uh unicode characters that 
dan is very fond of and so on so this is the the parser part of the 
implementation of dan's thing and there's also a type checker and 
code generator that are written by pattern matching on those data 
structures that i'm creating on the right hand side

## symbol table type checking object orientation
[56:05](https://youtu.be/GSeY1oD7dN0?t=3365)
and the so it's a 
it's a fairly you know the one of the cool things about dan's 
language is that in addition to you know types being used for making 
sure that you don't get things wrong the the types matter a lot for 
efficient code generation for nile and uh it turned out to be 
relatively straightforward to keep track of types in these grammars 
since you know the grammars are kind of like class um grammar and 
omega is pretty much like a class in an object-oriented language you 
can have state associated with running instances of that grammar and 
then you can keep the symbol table on there and and so on and uh and 
do proper type checking so i think i'm going to stop here sorry if i 
ran a little long and hassam is going to take over uh there is no 
this particular approach to translation this style is uh and just to 
clarify pegs on their own don't support left recursion but there's a 
cool trick that you can do with a memo table that's used by 
background parsers i wrote a paper about that if you guys are 
interested i answered a question you have all of these levels so 
right now i don't have a great answer to that i try it out um and 
hopefully it works but uh we're hoping that at some point soon we're 
going to be able to use the for instance the nile programs that dan 
has i kind of think of them as the meaning of the thing that i care 
about and it would be really great to have an automatic way to check 
the meaning again we can discuss it offline

memo table back parser warth