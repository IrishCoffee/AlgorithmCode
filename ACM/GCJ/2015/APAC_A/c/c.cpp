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

const int N_SIZE = 105;
const int M_SIZE = 10005;
long long dist[N_SIZE][N_SIZE];
int N,M;
int na[M_SIZE];
int nb[M_SIZE];
int cost[M_SIZE];

int main()
{
	freopen("in","r",stdin);
	freopen("c_out","w",stdout);

	int T,cas;
	scanf("%d",&T);
	cas = 0;

	while(T--)
	{
		scanf("%d%d",&N,&M);
		memset(dist,0,sizeof(dist));

		int a,b;
		int c;
		for(int i = 0; i < M; ++i)
		{
			scanf("%d%d%d",&a,&b,&c);
			na[i] = a;
			nb[i] = b;
			cost[i] = c;
			if((dist[a][b] == 0 ) || (dist[a][b] > c))
				dist[a][b] = c;
			dist[b][a] = dist[a][b];
		}

		for(int k = 0; k < N; ++k)
		{
			for(int i = 0; i < N; ++i)
			{
				if(dist[i][k] == 0)
					continue;
				for(int j = 0; j < N; ++j)
				{
					if(dist[j][k] == 0)
						continue;

					if((dist[i][j] == 0 && i != j ) || (dist[i][j] > dist[i][k] + dist[k][j]))
					{
						dist[i][j] = dist[i][k] + dist[k][j];
						dist[j][i] = dist[i][j];
					}
				}
			}
		}
		bool flag = false;
		
		printf("Case #%d:\n",++cas);
		
		for(int k = 0; k < M; ++k)
		{
			a = na[k];
			b = nb[k];
			c = cost[k];
			flag = false;
			for(int i = 0; i < N; ++i)
			{
				for(int j = 0; j < N; ++j)
				{
					if(i == j)
						continue;
					if(a == i && b == j && dist[i][j] == c)
					{
						flag = true;
						break;
					}
					if(dist[i][j] == dist[i][a] + c + dist[b][j])
					{
						flag = true;
						break;
					}
				}
				if(flag)
					break;
			}
			if(!flag)
				printf("%d\n",k);
		}
	}

	return 0;
}
