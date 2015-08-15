#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;
#define INF 0x03F3F3F3F
#define N 1024
int map[N][N];
int path[N];
void print_path(int node)
{
	if(path[node] == -1)
	{
		printf("%d ",node + 1);
		return;
	}
	else
	{
		print_path(path[node]);
		printf("%d ",node + 1);
	}
	return;
}
int main()
{
	freopen("input","r",stdin);
	int lowercost[N],nv,ne,source;
	bool visited[N];
	
	scanf("%d%d",&nv,&ne);
	//initialize
	for(int i = 0; i < nv;++i)
	{
		lowercost[i] = INF;
		visited[i] = false;
		for(int j = 0; j < nv; ++j)
			map[i][j] = map[j][i] = INF;
	}

	for(int i = 0; i < ne;++i)
	{
		int p,q,w;
		scanf("%d%d%d",&p,&q,&w);
		map[p][q] = map[q][p] = w;
    }

	scanf("%d",&source);
	for(int i = 0; i < nv; ++i)
	{
		lowercost[i] = map[source][i];
		path[i] = source;
	}

	lowercost[source] = 0;
	path[source] = -1; // mark for the root
    visited[source] = true;
	int pre = source;

	for(int i = 0; i < nv;++i)
	{
		int min = INF;
		//find the smallest one
		for(int j = 0; j < nv; ++j)
		{
			if(!visited[j] && lowercost[j] < min)
			{
				min = lowercost[j];
				pre = j;
			}
		}
		visited[pre] = true;
		//update
		for(int j = 0; j < nv;++j)
		{
			if(!visited[j] && lowercost[pre] + map[pre][j] < lowercost[j])
			{
				lowercost[j] = lowercost[pre] + map[pre][j];
				path[j] = pre;
			}
		}
//		cout << "pre " << pre + 1<< endl;
//	    for(int i = 0; i < nv; ++i)
//			printf("%d ",lowercost[i]);
//		cout << endl;	
	}
//	cout << "final result " << endl;

	for(int i = 0; i  < nv; ++i)
	{
		printf("Node %d cost = %2d  path: ",i+1,lowercost[i]);
		print_path(i);
		printf("\n");
	}
	return 0;
}
