#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
#define SIZE 1024
struct NODE
{
	int L,R,val,color;
}segTree[4 * SIZE];
void build(int L,int R,int root)
{
	segTree[root].L = L;
	segTree[root].R = R;
	segTree[root].val = 0;
	segTree[root].color = false;
	if(L == R)
		return;
	int mid = (L + R) >> 1;
	build(L,mid,root * 2);
	build(mid+1,R,root * 2 + 1);
}
void update(int start,int end,int root,int val)
{
	int L = segTree[root].L;
	int R = segTree[root].R;
	if(L == R)
	{
		segTree[root].val = max(segTree[root].val,val);
		return;
	}
	if(!segTree[root].color) // pure color
	{
		if(segTree[root].val >= val)
			return;
		else if(L == start && R == end)
		{
			segTree[root].val = val;
			return;
		}
	}
	int mid = (L + R) >> 1;
	if(start <= mid) 
		update(start,min(mid,end),root * 2,val);
	if(end > mid)
		update(max(mid + 1,start),end,root * 2 + 1,val);
	segTree[root].color = true;
}
int query(int P,int root,int val)
{
	int now = max(val,segTree[root].val);
	if(!segTree[root].color)
		return now;
	int mid = (segTree[root].L + segTree[root].R) >> 1;
	if(P <= mid)
		return query(P, root * 2,now);
	else
		return query(P, root * 2 + 1,now);
}
int main()
{
	
	int start,end,root = 1,val;
	int N,Q;
	scanf("%d%d%d",&start,&end,&N);
	build(start,end,root);
	while(N--)
	{
		scanf("%d%d%d",&start,&end,&val);
		update(start,end,root,val);
	}
	int point;
	scanf("%d",&Q);
	while(Q--)
	{
		scanf("%d",&point);
		printf("%d\n",query(point,root,0));
	}
	return 0;

}

