bits(0).
bits(1).
bitsgen(0,[]):-!.
bitsgen(X,[Y|L1]) :- X1 is X-1,bitsgen(X1,L1),bits(Y).
