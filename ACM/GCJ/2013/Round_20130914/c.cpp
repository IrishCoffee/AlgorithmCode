#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
char name[128][128];
bool cmp(int a,int b)
{
	int len1 = strlen(name[a]);
	int len2 = strlen(name[b]);
	bool flag = false;
	for(int i = 0; i < len1 && i < len2;++i)
	{
		if(name[a][i] > name[b][i])
			return false;
		else if(name[a][i] < name[b][i])
			return true;
	}
	if(len1 < len2)
		return true;
	else
		return false;
}
int main()
{
	freopen("in","r",stdin);
	freopen("out","w",stdout);
	int T,N,cases = 0;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%*c",&N);
		for(int i = 0; i < N; ++i)
			scanf("%[^\n]%*c",name[i]);
		if(N == 1)
		{
			printf("Case #%d: 0\n",++cases);
			continue;
		}
		int bottom = 0;
		int cost = 0;
		for(int i = 1; i < N; ++i)
		{
			if(cmp(bottom,i))
				bottom = i;
			else
				cost++;
		}
		printf("Case #%d: %d\n",++cases,cost);
	}
	return 0;
}



