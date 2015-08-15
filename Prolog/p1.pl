length([],0) :- !.
length([X|Y],N) :- length(Y,N1), N is N1 + 1.

getMiddle(X,[X|_],1) :- !.
getMiddle(X,[_|L],N) :- N > 1, N1 is N - 2, getMiddle(X,L,N1).




middle(L,X) :- length(L,N), getMiddle(X,L,N).
