#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <map>
#include <stack>
#include <queue>
#include <cstring>
using namespace std;

char name[128][128];
int main()
{
	freopen("in","r",stdin);
	freopen("c_out","w",stdout);

	int T,cas,N;
	scanf("%d",&T);
	cas = 0;
	int cnt = 0;
	while(T--)
	{
		cnt = 0;
		scanf("%d",&N);
		cin.get();
		for(int i = 0; i < N; ++i)
			cin.getline(name[i],128);
		
		for(int i = 1; i < N; ++i)
		{
			for(int j = 0; j < i; ++j)
			{
				if(strcmp(name[i],name[j]) < 0)
				{
					cnt++;
					break;
				}
			}
		}
		printf("Case #%d: %d\n",++cas,cnt);

	}

	return 0;
}
