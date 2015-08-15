/*POJ 2777 SegmentTree */
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
#define SIZE 100000
struct NODE
{
	int L,R,c;
	bool colored;
}segTree[3 * SIZE + 5];
int color_flag[32]; // at most 30 kinds of colors
void buildTree(int l,int r,int root)
{
	segTree[root].L = l;
	segTree[root].R = r;
	segTree[root].c = 1; // white
	segTree[root].colored = false; // pure color
	if(l == r) // leaf 
		return;
	int mid = (l + r) >> 1;
	buildTree(l,mid,root * 2);
	buildTree(mid + 1,r,root * 2 + 1);
}
void update(int l,int r,int c,int root)
{
	if(l > r)
		return;
	int L = segTree[root].L;
	int R = segTree[root].R;
	int mid = (L + R) >> 1;
	if(L == l && R == r) // same length, can be covered totally
	{
		segTree[root].c = c;
		segTree[root].colored = false;
		return;
	}
	if(!segTree[root].colored && segTree[root].c == c) // total covered because of the same color
		return;
	if(!segTree[root].colored) // the current segment's color is pure, so we need to pass its color to its children together with the pure state
	{
		segTree[root * 2].c = segTree[root * 2 + 1].c = segTree[root].c;
		segTree[root * 2].colored = segTree[root * 2 + 1].colored = false;
	}
	//update children
	if(l <= mid)
		update(l,min(mid,r),c,root * 2);
	if(r > mid)
		update(max(l,mid + 1),r,c,root * 2 + 1);
	segTree[root].colored = true;
}

int query(int l,int r,int root)
{
	int L = segTree[root].L;
	int R = segTree[root].R;
	int mid = (L + R) >> 1;
	if(!segTree[root].colored || L == R)
		return  1 << (segTree[root].c - 1);
	int ans = 0;
	if(l <= mid)
		ans |= query(l,min(mid,r), root * 2);
	if(r > mid)
		ans |= query(max(mid+1,l),r, root * 2 + 1);
	return ans;
}

int main()
{
	int L,T,O;
	for(int i = 1; i <= 30; ++i)
		color_flag[i] = 1 << (i-1);
	scanf("%d%d%d",&L,&T,&O);
	int root = 1;
	buildTree(1,L,root);
	int l,r,c;
	char op[2];
	while(O--)
	{
		scanf("%s",op);
		if(op[0] == 'C')
		{
			scanf("%d%d%d",&l,&r,&c);
			update(max(1,min(l,r)),max(l,r),c,root);
		}
		else
		{
			scanf("%d%d",&l,&r);
			int ans = query(max(1,min(l,r)),max(l,r),root);
			int cnt = 0;
			for(int i = 1; i <= T;++i)
				if(ans & (1 << (i-1)))
					++cnt;
			printf("%d\n",cnt);
		}

	}
	return 0;
}
