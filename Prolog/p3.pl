a(ala).
a(ama).
b(bala).
b(bama).
f(X,Y) :- a(X),b(Y).
f(X,Y) :- b(X), \+(X=Y),b(Y).
f(X,Y) :- b(X),!,a(Y).
