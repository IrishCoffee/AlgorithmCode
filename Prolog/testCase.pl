%%%test1
listmirror(L,[1,2,2,1]).
listmirror([1,2,3,4],L).
listmirror(L,[aa,bb,cc,dd,ee,ee,dd,cc,bb,aa]).
listmirror([],[]).
listmirror([1],[]).

%%%test2
listdiff([],[1,2],L).
listdiff([],[],L).
listdiff([1,2,3,d,t],[1,d],L).
listdiff([a,b,c,1,3,2],[3,c,2,b,1,a],[]).
listdiff([a,b,c,1,3,2],[3,c,2,b,4,a],[1]).

%%%test3
insert(3,[1,4,7],L).
insert(7,[],[7]).
insert(8,[1,3,5,7,9],[1,3,8,5,7,9]).
insert(8,[1,3,5,7,9],L), L == [1,3,5,7,8,9].
insert(0,[1,2,3,4,5],L).

%%%test4
bitsgen(0,X),L).
bitsgen(1,X),L).
bitsgen(2,X),L).
bitsgen(3,X),L).
bitsgen(4,X),L).
%%%test5
preorder(t(a, t(b, nil, nil), t(c, t(d, nil, nil),t(e, nil, nil))),L).
preorder(t(a, t(b, t(c, nil,nil),t(d,nil,nil)),t(e, t(f, nil, nil),t(g, nil, nil))),L).
preorder(t(a, nil, nil), L).
preorder(nil,L).
preorder(t(a, nil, nil), [a,b]).

