#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
struct NODE
{
	int id;
	int mk;
}node[1024];
bool cmp(NODE a,NODE b)
{
	if(a.mk < b.mk)
		return true;
	if(a.mk == b.mk && a.id < b.id)
		return true;
	return false;
}
int main()
{
//	freopen("in.txt","r",stdin);
//	freopen("b_out.txt","w",stdout);
	int T;
	int cas = 0;
	int B,N;
	int seq[1000000];
	int cnt[1005];
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&B,&N);
		for(int i = 0; i < B; ++i)
		{
			node[i].id = i;
			scanf("%d",&node[i].mk);
		}
		sort(node,node + B,cmp);
		memset(cnt,0,sizeof(cnt));
		
		//start
		for(int i = 0; i <= node[i].id; ++i)
		{
			seq[i] = i;
			cnt[i]++;
			len++;
		}

		int startLoopID = 
		for(int i = 0; i < len; ++i)
			cout << seq[i] << " ";
		cout << endl;
//		printf("Case #%d: %lld %lld\n",++cas,ans1,ans2);
	}
	return 0;
}
