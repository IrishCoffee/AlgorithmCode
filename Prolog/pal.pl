palindrome([]) :- !.
palindrome([_]) :- !.
palindrome([F|R]) :- append(S,[F],R), !, palindrome(S).
