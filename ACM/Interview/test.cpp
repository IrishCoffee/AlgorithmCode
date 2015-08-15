#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

#define SIZE 10000

struct Node
{
	int L, R, count;
	bool colored;
}segTree[SIZE * 4 + 5];
void buildTree(int L,int R, int root)
{
	segTree[root].L = L;
	segTree[root].R = R;
	segTree[root].count = 0;
	segTree[root].colored = false;
	if(L == R) return;
	int mid = (L + R) / 2;
	buildTree(L, mid, root * 2);
	buildTree(mid+1, R, root * 2 + 1);
}

void update(int start, int end, int root)
{
	int L = segTree[root].L;
	int R = segTree[root].R;

	if(!segTree[root].colored)
	{
		if(start == L && end == R)
		{
			segTree[root].count++;
			return;
		}
		segTree[2*root].count += segTree[root].count;
		segTree[2*root+1].count += segTree[root].count;
		segTree[2*root].colored += segTree[2*root+1].colored = false;
		segTree[root].colored = true;
		segTree[root].count = 0;
	}
	int mid = (L+R) >> 1;
	if(start <= mid)
		update(start, min(mid, end), 2*root);
	if(end > mid)
		update(max(mid+1, start), end, 2*root+1);
	segTree[root].colored = true;
}

void query(int color[], int root)
{
	int L = segTree[root].L;
	int R = segTree[root].R;
	if(!segTree[root].colored)
	{
		color[segTree[root].count % 3] += R - L + 1;
		return;
	}
	query(color,root * 2);
	query(color,root * 2 + 1);
}

int main()
{
	int N,M;
	while(scanf("%d%d",&N, &M) == 2)
	{
		int root = 1;
		buildTree(1,N,root);
		int l,r,c;
		while(M--)
		{
			scanf("%d%d",&l,&r);
			update(max(1,l),min(N,r),root);
		}
		int color[3];
		memset(color,0,sizeof(color));
		query(color,root);
		printf("%d %d %d\n",color[0],color[1],color[2]);
	}
	return 0;
}
