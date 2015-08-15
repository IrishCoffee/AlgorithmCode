#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <cstring>
#include <algorithm>
#include <queue>
#include <map>
#include <stack>
using namespace std;

int mat[51][51];
bool flag[51];
int N,Q;

void dfs(int cur,int end,int &ans,int &del_a,int &del_b,int old_a,int old_b,int old_day)
{
//	printf("cur %d end %d ans %d old_a %d old_b %d old_day %d\n",cur,end,ans,old_a,old_b,old_day);
	if(cur == end)
	{
		if(ans == -1 || ans < old_day)
		{
			ans = old_day;
			del_a = old_a;
			del_b = old_b;
		}
		return;
	}
	for(int i = 1; i <= N; ++i)
	{
		if(!flag[i])
			continue;
		if(i == cur)
			continue;
		if(mat[i][cur] == 0)
			continue;
		flag[i] = false;
		if(mat[i][cur] < old_day)
			dfs(i,end,ans,del_a,del_b,i,cur,mat[i][cur]);
		else
			dfs(i,end,ans,del_a,del_b,old_a,old_b,old_day);
		flag[i] = true;
	}
}
int main()
{
	memset(mat,0,sizeof(mat));
	char query[8];
	int a,b;
	scanf("%d%d",&N,&Q);
	int date = 0;
	while(Q--)
	{
		date++;
		scanf("%s%d%d",query,&a,&b);
		if(query[0] == 'b')
		{
			mat[a][b] = date;
			mat[b][a] = date;
		}
		else 
		{
			int del_a,del_b;
			int ans = -1;
			
			for(int i = 1; i <= N; ++i)
			{
				if(i == a || mat[a][i] == 0)
					continue;
				memset(flag,true,sizeof(bool) * 51);
				flag[i] = false;
				dfs(i,b,ans,del_a,del_b,i,a,mat[i][a]);
			}
			if(ans == -1)
				printf("NO\n");
			else
			{
				printf("YES %d\n",ans);
				mat[del_a][del_b] = 0;
				mat[del_b][del_a] = 0;
			}
		}
	}

	return 0;
}
