jedi(luke).
jedi(yoda).
sith(vader).
sith(maul).
fight(X,Y) :- jedi(X),sith(Y).
fight(X,Y) :- sith(X), X \= Y, sith(Y).
fight(X,Y) :- jedi(X), !, jedi(Y).
