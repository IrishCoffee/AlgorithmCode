#include <string>
#include <vector>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;

class LuckyCycle {
	public:
		int mat[128][128];
		int N;

		void dfs(int start_node,int from_node,int cur_node,int cnt_node,int cnt_4,int cnt_7,vector<int> &v)
		{
			bool flag = false;
			//	printf("start %d from %d cur %d node_cnt %d cnt_4 %d cnt_7 %d\n",start_node,from_node,cur_node,cnt_node,cnt_4,cnt_7);
			for(int i = 1; i <= N; ++i)
			{
				if(i == cur_node)
					continue;
				if(mat[cur_node][i] == 4 && i != from_node)
				{
					flag = true;
					dfs(start_node,cur_node,i,cnt_node + 1,cnt_4 + 1, cnt_7,v);
				}
				if(mat[cur_node][i] == 7 && i != from_node)
				{
					flag = true;
					dfs(start_node,cur_node,i,cnt_node + 1,cnt_4, cnt_7 + 1,v);
				}
			}
			if(!flag) // cannot continue
			{
				if(cnt_node % 2 == 0 && start_node != cur_node)
				{
					if(cnt_7 - cnt_4 == 1)
					{
						if(mat[start_node][cur_node] != 0)
							return;
						if(v.size() == 0)
						{
							v.push_back(start_node);
							v.push_back(cur_node);
							v.push_back(4);

						}
					}
					if(cnt_4 - cnt_7 == 1)
					{
						if(mat[start_node][cur_node] != 0)
							return;
						if(v.size() == 0)
						{
							v.push_back(start_node);
							v.push_back(cur_node);
							v.push_back(7);
						}
					}
				}
				return;
			}
		}

		vector <int> getEdge(vector <int> edge1, vector <int> edge2, vector <int> weight) 
		{
			memset(mat,0,sizeof(mat));
			N = edge1.size() + 1;
			for(int i = 0; i < N - 1; ++i)
			{
				int a = edge1[i];
				int b = edge2[i];
				mat[a][b] = weight[i];
				mat[b][a] = mat[a][b];
			}
			vector<int> ans;
			for(int i = 1; i <= N; ++i)
			{
				dfs(i,i,i,1,0,0,ans);
				if(ans.size() != 0)
					return ans;
			}
			return ans;
		}
};
/*
   int main()
   {
   LuckyCycle sol;
   vector<int> e1;
   vector<int> e2;
   vector<int> w;

   int ee1[5] = {1,2,3,5,6};
   int ee2[5] = {2,3,4,3,5};
   int ww[5] = {4,7,7,7,7};

   for(int i = 0; i < 5; ++i)
   {
   e1.push_back(ee1[i]);
   e2.push_back(ee2[i]);
   w.push_back(ww[i]);
   }
   vector<int> v = sol.getEdge(e1,e2,w);
   cout << v.size() << endl;
   if(v.size() != 0)
   cout << v[0] << " " << v[1] << " " << v[2] << endl;
   return 0;
   }
   */
