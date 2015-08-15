:- begin_tests(lists).
:- use_module(library(lists)).
bits(0).
bits(1).
bitsgen(0,[]):-!.
bitsgen(X,[Y|L1]) :- X1 is X-1,bitsgen(X1,L1),bits(Y).

%%%test4
test(bitsgen) :- findall(X,bitsgen(0,X),L),permutation(L,[[]]).
test(bitsgen) :- findall(X,bitsgen(1,X),L),permutation(L,[[0],[1]]).
test(bitsgen) :- findall(X,bitsgen(2,X),L),permutation(L,[[0,0],[0,1],[1,0],[1,1]]).
test(bitsgen) :- findall(X,bitsgen(3,X),L),permutation(L,[[0,0,0],[0,0,1],[0,1,0],[0,1,1],[1,0,0],[1,0,1],[1,1,0],[1,1,1]]).
test(bitsgen) :- findall(X,bitsgen(4,X),L),permutation(L,[[0,0,0,0],[0,0,0,1],[0,0,1,0],[0,0,1,1],[0,1,0,0],[0,1,0,1],[0,1,1,0],[0,1,1,1],[1,0,0,0],[1,0,0,1],[1,0,1,0],[1,0,1,1],[1,1,0,0],[1,1,0,1],[1,1,1,0],[1,1,1,1]]).

:- end_tests(lists).
