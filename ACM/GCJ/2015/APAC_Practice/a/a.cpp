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

int mat[256][256];
int color[256];
bool bfs(int cur,int N)
{
	queue<int> q;
	q.push(cur);
	color[cur] = 1;
	while(!q.empty())
	{
		cur = q.front();
		q.pop();
		for(int i = 1; i <= N; ++i)
		{
			if(mat[i][cur] && color[i] == -1) //not colored
			{
				q.push(i);
				color[i] = !color[cur];
			}
			if(mat[i][cur] && color[i] == color[cur])
				return false;
		}
	}
	return true;
}
int main()
{
	freopen("in","r",stdin);
	freopen("a_out","w",stdout);

	int cas,cas_N;
	scanf("%d",&cas);
	cas_N = 0;
	int M;
	bool ok;
	while(cas--)
	{
		ok = true;
		memset(mat,0,sizeof(mat));
		memset(color,-1,sizeof(color));
		int node1,node2;
		string s1,s2;
		map<string,int> getId;
		map<string,int>::iterator it;
		scanf("%d",&M);
		int id = 0;
		int node_cnt = 1;
		while(M--)
		{
			cin >> s1 >> s2;
			it = getId.find(s1);
			if(it == getId.end())
			{
				getId[s1] = node_cnt;
				node1 = node_cnt;
				node_cnt++;
			}
			else
				node1 = getId[s1];
			
			it = getId.find(s2);
			if(it == getId.end())
			{
				getId[s2] = node_cnt;
				node2 = node_cnt;
				node_cnt++;
			}
			else
				node2 = getId[s2];
			mat[node1][node2] = 1;
			mat[node2][node1] = 1;
		}
		node_cnt--;
		ok = true;
		for(int i = 1; i <= node_cnt; ++i)
		{
			if(color[i] == -1 && !bfs(i,node_cnt))
			{
				ok = false;
				break;
			}
		}
		if(ok)
			printf("Case #%d: Yes\n",++cas_N);
		else
			printf("Case #%d: No\n",++cas_N);

	}

	return 0;
}
