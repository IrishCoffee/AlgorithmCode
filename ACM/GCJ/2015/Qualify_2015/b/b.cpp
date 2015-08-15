#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
using namespace std;
void dfs(vector<int> dinner,int D,int cur,int &ans)
{
	int max_dinner = dinner[0];
	int index = 0;
	bool finished = true;
	for(int i = 0; i < D; ++i)
	{
		if(dinner[i] > max_dinner)
		{
			max_dinner = dinner[i];
			index = i;
		}
		if(dinner[i])
			finished = false;
	}
	if(finished)
	{
		if(ans == -1)
			ans = cur;
		else
			ans = min(ans,cur);
		return;
	}
	if(max_dinner <= 3)
	{
		if(ans == -1)
			ans = cur + max_dinner;
		else
			ans = min(cur + max_dinner,ans);
		return;
	}
	else
	{
		if(max_dinner != 9)
		{
			dinner[index] = max_dinner / 2 + max_dinner % 2;
			dinner.push_back(max_dinner / 2);
			dfs(dinner,D + 1,cur+1,ans); // special miniute
			dinner[index] = max_dinner;
			dinner.pop_back();
		}
		else
		{
			dinner[index] = 3;
			dinner.push_back(6);
			dfs(dinner,D + 1,cur+1,ans); // special miniute
			dinner[index] = max_dinner;
			dinner.pop_back();
		}
	}
	for(int i = 0; i < D; ++i)
	{
		if(dinner[i])
			dinner[i]--;
	}
	dfs(dinner,D,cur+1,ans);
}
int main()
{
	freopen("in.txt","r",stdin);
	freopen("b_out.txt","w",stdout);
	int T;
	int cas = 0;
	int D;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&D);
		vector<int> dinner;
		dinner.clear();
		for(int i = 0; i < D; ++i)
		{
			int tmp;
			scanf("%d",&tmp);
			dinner.push_back(tmp);
		}
		int ans = -1;
		dfs(dinner,D,0,ans);
		printf("Case #%d: %d\n",++cas,ans);
	}
	return 0;
}
