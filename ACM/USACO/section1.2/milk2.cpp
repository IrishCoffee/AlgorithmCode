/*
ID: irishco1
PROG: milk2
LANG: C++
*/
#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;

int N;
struct NODE
{
	int start,end;
}node[1000005];

bool cmp(NODE a,NODE b)
{
	if(a.start < b.start)
		return true;
	else if(a.start == b.start && a.end < b.end)
		return true;
	return false;
}

int main()
{
	freopen("milk2.in","r",stdin);
	freopen("milk2.out","w",stdout);
	scanf("%d",&N);
	for(int i = 0; i < N; ++i)
		scanf("%d%d",&node[i].start,&node[i].end);
	sort(node,node + N, cmp);
	int lmax = node[0].end - node[0].start, lmin = 0;
	int s = node[0].start, e = node[0].end;
	int tmp;
	for(int i = 1; i < N; ++i)
	{
		if(node[i].start <= e)
		{
			if(node[i].end > e)
			{
				e = node[i].end;
				tmp = e - s;
				if(lmax < tmp)
					lmax = tmp;
			}
		}
		else
		{
			tmp = node[i].start - e;
			if(lmin < tmp)
				lmin = tmp;
			s = node[i].start;
			e = node[i].end;
		}
	}
	printf("%d %d\n",lmax,lmin);
	return 0;
}




