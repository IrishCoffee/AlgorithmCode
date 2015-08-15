%%%test1
test(listmirror) :- listmirror(L,[1,2,2,1]), L == [1,2].
test(listmirror) :- listmirror([1,2,3,4],L), L == [1,2,3,4,4,3,2,1].
test(listmirror) :- listmirror(L,[aa,bb,cc,dd,ee,ee,dd,cc,bb,aa]), L = [aa,bb,cc,dd,ee].
test(listmirror) :- listmirror([],[]).
test(listmirror) :- \+ listmirror([1],[]).

%%%test2
test(listdiff) :- listdiff([],[1,2],L), L == [].
test(listdiff) :- listdiff([],[],L), L == [].
test(listdiff) :- listdiff([1,2,3,d,t],[1,d],L), L == [2,3,t].
test(listdiff) :- listdiff([a,b,c,1,3,2],[3,c,2,b,1,a],[]).
test(listdiff) :- listdiff([a,b,c,1,3,2],[3,c,2,b,4,a],[1]).

%%%test3
test(insert) :- insert(3,[1,4,7],L), L == [1,3,4,7].
test(insert) :- insert(7,[],[7]).
test(insert) :- \+ insert(8,[1,3,5,7,9],[1,3,8,5,7,9]).
test(insert) :- insert(8,[1,3,5,7,9],L), L == [1,3,5,7,8,9].
test(insert) :- insert(0,[1,2,3,4,5],L), L == [0,1,2,3,4,5].

%%%test4
test(bitsgen) :- findall(X,bitsgen(0,X),L),permutation(L,[[]]).
test(bitsgen) :- findall(X,bitsgen(1,X),L),permutation(L,[[0],[1]]).
test(bitsgen) :- findall(X,bitsgen(2,X),L),permutation(L,[[0,0],[0,1],[1,0],[1,1]]).
test(bitsgen) :- findall(X,bitsgen(3,X),L),permutation(L,[[0,0,0],[0,0,1],[0,1,0],[0,1,1],[1,0,0],[1,0,1],[1,1,0],[1,1,1]]).
test(bitsgen) :- findall(X,bitsgen(4,X),L),permutation(L,[[0,0,0,0],[0,0,0,1],[0,0,1,0],[0,0,1,1],[0,1,0,0],[0,1,0,1],[0,1,1,0],[0,1,1,1],[1,0,0,0],[1,0,0,1],[1,0,1,0],[1,0,1,1],[1,1,0,0],[1,1,0,1],[1,1,1,0],[1,1,1,1]]).
%%%test5
test(preorder) :- preorder(t(a, t(b, nil, nil), t(c, t(d, nil, nil),t(e, nil, nil))),L), L == [a,b,c,d,e].
test(preorder) :- preorder(t(a, t(b, t(c, nil,nil),t(d,nil,nil)),t(e, t(f, nil, nil),t(g, nil, nil))),L), L == [a,b,c,d,e,f,g].
test(preorder) :- preorder(t(a, nil, nil), L), L == [a].
test(preorder) :- preorder(nil,L), L == [].
test(preorder) :- \+ preorder(t(a, nil, nil), [a,b]).

