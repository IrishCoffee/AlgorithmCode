#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
struct NODE
{
	int x1,y1,x2,y2;
}node[1024];
long long fabs(long long a,long long b)
{
	long long tmp = a-b;
	if(tmp < 0)
		return -1 * tmp;
	else
		return tmp;
}
int main()
{
	freopen("input","r",stdin);
	freopen("out","w",stdout);
	int T,B,cases = 0;
	scanf("%d",&T);
	while(T--)
	{
		int ans_x,ans_y;
		scanf("%d",&B);
		for(int i = 0; i < B; ++i)
			scanf("%d%d%d%d",&node[i].x1,&node[i].y1,&node[i].x2,&node[i].y2);
	    long long dis = 0,tmp_dis = 0;
		bool flag = true;
		for(int i = 0; i < B; ++i)
		{
			int x,y;
			for(int j = node[i].x1;j <= node[i].x2; ++j)
			{
				x = j;
				for(int k = node[i].y1;k <= node[i].y2; ++k)
				{
					y = k;
					tmp_dis = 0;
					for(int m = 0; m < B; ++m)
					{
						for(int p = node[m].x1; p <= node[m].x2; ++p)
							for(int q = node[m].y1; q <= node[m].y2; ++q)
								tmp_dis += fabs((long long)p,(long long)x) + fabs((long long)q,(long long)y);
					}
					if(flag || dis > tmp_dis)
					{
						flag = false;
						dis = tmp_dis;
						ans_x = x;
						ans_y = y;
					}
					else if(dis == tmp_dis)
					{
						if(x < ans_x)
						{
							ans_x = x;
							ans_y = y;
						}
						else if(x == ans_x && y < ans_y)
						{
							ans_x = x;
							ans_y = y;
						}
					}
				}
			}
		}
		printf("Case #%d: %d %d %lld\n",++cases,ans_x,ans_y,dis);
	}
}


