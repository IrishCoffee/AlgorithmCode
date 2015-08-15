%%%[1,2,3] -> [1,1,2,1,2,3]
%[1,2,3,4] -> [1,1,2,1,2,3,1,2,3,4]
firstN([X|_],1,[X]) :- !.
firstN([X|T],N,[X|L]) :- N > 1, N1 is N-1, firstN(T,N1,L).
dupN(L1,0,[]) :- !.
dupN(L1,N,L) :- N > 0, N1 is N-1, dupN(L1,N1,L2),firstN(L1,N,L3),append(L2,L3,L).

dup(L1,L) :- length(L1,N), dupN(L1,N,L),!.

%%%Find the middle number of a list 
%[1,3,2] -> 3
%[4,1,3,5,7] -> 3
%[1,4,4,3,5] -> 4
length([],0) :- !.
length([X|Y],N) :- length(Y,N1), N is N1 + 1.

getMiddle(X,[X|_],1) :- !.
getMiddle(X,[_|L],N) :- N > 1, N1 is N - 2, getMiddle(X,L,N1).

middle(L,X) :- length(L,N), getMiddle(X,L,N).
