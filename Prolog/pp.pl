bitsgen(1,[0]).
bitsgen(1,[1]).
bitsgen(X,L) :- X>1, X1 is X-1,bitsgen(X1,L1), append([0],L1,L).
bitsgen(X,L) :- X>1, X1 is X-1, bitsgen(X1,L1), append([1],L1,L).
