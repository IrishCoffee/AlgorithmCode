#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

bool mat[128][128];
bool visited[128];
int N,M,K;
int score[128];
int musted[128];
bool check()
{
	for(int i = 0; i < K; ++i)
		if(!visited[musted[i]])
			return false;
	return true;
}
void dfs(int now,int &ans,int cnt,int tmp)
{
	if(cnt == M)
	{
		if(check())
			ans = max(tmp,ans);
		return;
	}
	for(int i = 1; i <= N; ++i)
	{
		if(mat[now][i] && !visited[i])
		{
			visited[i] = true;
			dfs(i,ans,cnt+1,tmp + score[i]);
		}
	}
}


	


int main()
{
	memset(mat,false,sizeof(mat));
	memset(visited,false,sizeof(visited));
	scanf("%d%d%d\n",&N,&K,&M);
	for(int i = 1;i <= N; ++i)
		scanf("%d",&score[i]);
	for(int i = 0; i < K; ++i)
		scanf("%d",&musted[i]);
	for(int i = 0; i < M; ++i)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		mat[a][b] = mat[b][a] = true;
	}
	if(K > M)
	{
		printf("-1\n");
		return 0;
	}
	int ans = -1;
	visited[1] = true;
	dfs(1,ans,1,score[1]);
	if(ans == 0)
		printf("-1\n");
	else
		printf("%d\n",ans);
	return 0;
}
	

	


