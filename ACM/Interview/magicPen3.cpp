/* HOJ 2681 magic pen Segment Tree */
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
#define SIZE 100000
struct NODE
{
	int L,R,c;
	bool colored;
}segTree[2 * SIZE + 5];

void buildTree(int l,int r,int root)
{
	segTree[root].L = l;
	segTree[root].R = r;
	segTree[root].c = 0; // white
	segTree[root].colored = false; // pure color
	if(l == r) // leaf 
		return;
	int mid = (l + r) >> 1;
	buildTree(l,mid,root * 2);
	buildTree(mid + 1,r,root * 2 + 1);
}
void update(int l,int r,int c,int root)
{
	int L = segTree[root].L;
	int R = segTree[root].R;
	int mid = (L + R) >> 1;
	if(L == l && R == r) // same length
	{
		segTree[root].c = c;
		segTree[root].colored = false;
		return;
	}
	if(!segTree[root].colored && segTree[root].c == c) // total covered
		return;
	if(!segTree[root].colored)
	{
		segTree[2*root].c = segTree[2*root+1].c = segTree[root].c;
		segTree[2*root].colored = segTree[2*root+1].colored = false;
	}
	if(l <= mid)
		update(l,min(mid,r),c,root * 2);
	if(r > mid)
		update(max(l,mid + 1),r,c,root * 2 + 1);
	segTree[root].colored = true;
}

int query(int root)
{
	int L = segTree[root].L;
	int R = segTree[root].R;
	int mid = (L + R) >> 1;
	if(!segTree[root].colored)
	{
		if(segTree[root].c == 0)
			return R - L + 1;
		else
			return 0;
	}
	else
		return query(root * 2) + query(root * 2 + 1);
}

int main()
{
	int N,M;
	while(scanf("%d%d",&N,&M) == 2)
	{
		int root = 1;
		buildTree(1,N,root);
		int l,r,c;
		while(M--)
		{
			scanf("%d%d%d",&l,&r,&c);
			update(max(1,l),r,c,root);
		}
		printf("%d\n",query(root));
	}
	return 0;
}
