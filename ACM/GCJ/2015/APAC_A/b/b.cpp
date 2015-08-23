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
using namespace std;

int len[1024];

int main()
{
	freopen("in","r",stdin);
	freopen("b_out","w",stdout);

	int T,cas;
	int N,M;
	int ai,bi;
	scanf("%d",&T);
	cas = 0;

	while(T--)
	{
		scanf("%d%d",&N,&M);
		for(int i = 0; i < N; ++i)
			scanf("%d",&len[i]);
		printf("Case #%d:\n",++cas);
		while(M--)
		{
			scanf("%d%d",&ai,&bi);
			double sum = 1.0;
			for(int i = ai; i <= bi; ++i)
				sum *= pow(len[i],1.0 / (bi - ai + 1));
			//printf("%.7lf\n",pow(sum,1.0 / (bi - ai + 1)));
			printf("%.7lf\n",sum);
			
		}

	}

	return 0;
}
