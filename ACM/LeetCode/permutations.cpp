#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;

class Solution
{
	public:
		vector<vector<int> > ans;
		vector<vector<int> > permute(vector<int> &num)
		{
			int size = num.size();
			bool flag[size];
			memset(flag,true,sizeof(flag));
			vector<int> v;
			if(size == 0)
				return ans;
			dfs(num,v,0,flag,size);
			return ans;
		}
		void dfs(vector<int> &num,vector<int> v,int k,bool flag[],int size)
		{
			if(k == size)
			{
				ans.push_back(v);
				return;
			}
			for(int i = 0; i < size; ++i)
			{
				if(flag[i])
				{
					flag[i] = false;
					v.push_back(num[i]);
					dfs(num,v,k+1,flag,size);
					v.pop_back();
					flag[i] = true;
				}
			}
		}
};
int main()
{
	Solution sol;
	vector<int> w;
	w.push_back(1);
	w.push_back(2);
	w.push_back(3);
	w.push_back(4);
	vector<vector<int> > v = sol.permute(w);
	for(int i= 0; i < v.size(); ++i)
	{
		for(int j = 0; j < v[i].size(); ++j)
			cout << v[i][j] << " ";
		cout << endl;
	}
	return 0;
}
