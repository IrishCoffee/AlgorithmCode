#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <map>
#include <stack>
#include <queue>
#include <cstring>
#include <cmath>
#include <string>
#include <climits>
using namespace std;

long long len[60];

int dfs(long long K,int cnt)
{
	for(int i = 1; i <= 60; ++i)
	{
		if(len[i - 1] < K && len[i] >= K)
		{
			if(i == 1 || (i == 2 && K == 2) || (len[i] + 1 - K == K))
			{
				if(cnt % 2)
					return 1;
				else
					return 0;
			}
			else
				return dfs(len[i] + 1 - K ,cnt+1);
		}
	}
}

int main()
{
	freopen("in","r",stdin);
	freopen("a_out","w",stdout);

	len[0] = 0;
	len[1] = 1;
	len[2] = 3;
	for(int i = 3; i <= 60; ++i)
		len[i] = 2 * len[i-1] + 1;

	int T,cas;
	scanf("%d",&T);
	cas = 0;

	long long K;
	while(T--)
	{
		scanf("%lld",&K);
		printf("Case #%d: %d\n",++cas,dfs(K,0));
	}

	return 0;
}
