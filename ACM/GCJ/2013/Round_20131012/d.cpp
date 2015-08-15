#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <queue>
using namespace std;

int map[128][128];
struct NODE
{
	int x,y,sum,step;
}start;
NODE vis[128][128];
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};
int main()
{
	freopen("input","r",stdin);
	freopen("out","w",stdout);
	int T,sx,sy,ex,ey;
	int N,M;
	int ans_sum;
	int cases = 0;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&N,&M);
		scanf("%d%d%d%d",&sx,&sy,&ex,&ey);
		for(int i = 0; i < N; ++i)
			for(int j = 0;j < M; ++j)
			{
				vis[i][j].step = 0;
				vis[i][j].sum = -1;
				scanf("%d",&map[i][j]);
			}
        start.x = sx;
		start.y = sy;
		start.sum = map[sx][sy];
		start.step = 1;
		vis[start.x][start.y].step = 1;
		vis[start.x][start.y].sum = start.sum;
		queue<NODE> q;
		q.push(start);
		bool cannot = true;
		while(!q.empty())
		{
			NODE tmp = q.front();
			q.pop();
			NODE next;
			int nx,ny;
			for(int i = 0; i < 4; ++i)
			{
				next.x = tmp.x + dx[i];
				next.y = tmp.y + dy[i];
				next.step = tmp.step + 1;
				next.sum = tmp.sum + map[next.x][next.y];
				if(next.x < 0 || next.x >= N || next.y < 0 || next.y >= M)
					continue;
				if(next.x == ex && next.y == ey)
				{
					if((vis[ex][ey].step == next.step && vis[ex][ey].sum < next.sum) || vis[ex][ey].step == 0 || vis[ex][ey].step > next.step)
					{
					cannot = false;
					vis[next.x][next.y].step = next.step;
					vis[next.x][next.y].sum = next.sum;
					ans_sum = next.sum;
					}

				}
				else if(map[next.x][next.y] != -1 && (vis[next.x][next.y].step == 0 || vis[next.x][next.y].step > next.step || (vis[next.x][next.y].step == next.step && vis[next.x][next.y].sum < next.sum)))
				{
					vis[next.x][next.y].step = next.step;
					vis[next.x][next.y].sum = next.sum;
					q.push(next);
				}

			}
		}
		printf("Case #%d: ",++cases);
		if(cannot)
			printf("Mission Impossible.\n");
		else
			printf("%d\n",ans_sum);

	}
}
