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

const int SIZE = 105;
int dist[SIZE][SIZE];
int path[SIZE][SIZE][SIZE];
int road[SIZE][SIZE];
bool checked[SIZE][SIZE];
bool used[10005];
int N,M;

void mark(int i,int j)
{
	int k;
	checked[i][j] = checked[j][i] = false;
	for(int m = 1; m <= path[i][j][0]; ++m)
	{
		k = path[i][j][m];

		if(road[i][k] == dist[i][k])
			used[road[i][k]] = true;

		if(road[k][i] == dist[i][k])
			used[road[k][i]] = true;

		if(road[k][j] == dist[k][j])
			used[road[k][j]] = true;
		if(road[j][k] == dist[k][j])
			used[road[j][k]] = true;

		if(checked[i][k])
			mark(i,k);
		if(checked[k][j])
			mark(k,j);
	}
}
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
		memset(path,0,sizeof(path));
		memset(road,-1,sizeof(road));
		memset(used,false,sizeof(used));
		memset(checked,true,sizeof(checked));

		int a,b,c;
		for(int i = 0; i < M; ++i)
		{
			scanf("%d%d%d",&a,&b,&c);
			dist[a][b] = dist[b][a] = c;
			road[a][b] = i;
		}
		for(int k = 0; k < N; ++k)
		{
			for(int i = 0; i < N; ++i)
			{
				if(dist[i][k] == 0)
					continue;
				for(int j = 0; j < N; ++j)
				{
					if((dist[i][j] == 0 && i != j ) || (dist[i][j] > dist[i][k] + dist[k][j]))
					{
						dist[i][j] = dist[i][k] + dist[k][j];
						dist[j][i] = dist[i][j];

						path[i][j][0] = 1;
						path[j][i][0] = 1;

						path[i][j][1] = k;
						path[j][i][1] = k;
					}
					else if(dist[i][j] == dist[i][k] + dist[k][j])
					{
						path[i][j][0]++;
						path[i][j][path[i][j][0]] = k;
						
						path[j][i][0]++;
						path[j][i][path[j][i][0]] = k;
					}
				}
			}
		}
		for(int i = 0; i < N; ++i)
			for(int j = 0; j < N; ++j)
			{
				if(checked[i][j])
					mark(i,j);
			}
		int cnt = 0;
		printf("Case #%d:\n",++cas);
		for(int i = 0; i < M; ++i)
		{
			if(!used[i])
				printf("%d\n",i);
		}
	}

	return 0;
}
