/*
ID: irishco1
PROG: milk
LANG: C++
*/
#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;

struct NODE
{
	int p,a;
}node[5005];

bool cmp(NODE a,NODE b)
{
	if(a.p < b.p)
		return true;
	if(a.p == b.p && a.a > b.a)
		return true;
	return false;
}

int main()
{
	freopen("milk.in","r",stdin);
	freopen("milk.out","w",stdout);
	int N,M;
	scanf("%d%d",&N,&M);
	for(int i = 0;i < M; ++i)
		scanf("%d%d",&node[i].p,&node[i].a);
	sort(node,node+M,cmp);
	int ans = 0;
	for(int i = 0; i < M; ++i)
	{
		if(N >= node[i].a)
		{
			N -= node[i].a;
			ans += node[i].a * node[i].p;
		}
		else
		{
			ans += N * node[i].p;
			N = 0;
		}
		if(N == 0)
			break;
	}
	printf("%d\n",ans);
	return 0;
}








