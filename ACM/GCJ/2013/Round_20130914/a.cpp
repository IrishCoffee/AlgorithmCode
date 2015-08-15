#include <iostream>
#include <cstdio>
#include <cstring>
#include <map>
using namespace std;

int G[1024][1024];
int vis[1024];
char name1[1024];
char name2[1024];
struct NODE
{
	char name[1024];
	int id;
}node[1024];
int num;
const int black = 1;
const int white = 2;
bool dfs(int id,int color)
{
	vis[id] = color;
	if(color == black)
		color = white;
	else
		color = black;
	for(int i = 0; i < num; ++i)
	{
		if(G[id][i])
		{
			if(vis[i] == 0)
			{
				if(!dfs(i,color))
					return false;
			}
			else if(vis[i] != 0 && vis[i] != color)
				return false;
		}
	}
	return true;
}
bool ranColor()
{
	for(int i = 0; i < num; ++i)
		if(vis[i] == 0)
			if(dfs(i,black) == false)	
				return false;
	return true;
}
int main()
{
	freopen("in","r",stdin);
	freopen("out","w",stdout);
	int T,M;
	int id1,id2;
	int cases = 0;
	scanf("%d",&T);
	while(T--)
	{
		num = 0;
		scanf("%d",&M);
		memset(G,0,sizeof(G));
		memset(vis,0,sizeof(vis));
		for(int j = 0; j < M;++j)
		{
			id1 = -1,id2 = -1;
			scanf("%s%s",name1,name2);
			for(int i = 0; i < num; ++i)
			{
				if(strcmp(name1,node[i].name) == 0)
					id1 = node[i].id;
				else if(strcmp(name2,node[i].name) == 0)
					id2 = node[i].id;
			}
			if(id1 == -1)
			{
				strcpy(node[num].name,name1);
				id1 = num;
				node[num].id = num++;
			}
			if(id2 == -1)
			{
				strcpy(node[num].name,name2);
				id2 = num;
				node[num].id = num++;
			}
			G[id1][id2] = G[id2][id1] = 1;
		}
	//	for(int i = 0; i < num; ++i)
	//		printf("%d %s\n",node[i].id,node[i].name);
		if(ranColor())
			printf("Case #%d: Yes\n",++cases);
		else
			printf("Case #%d: No\n",++cases);
	}
}



