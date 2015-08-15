#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

class Solution
{
	public:
		vector<vector<int> > ans;
		vector<vector<int> > combinationSum(vector<int> &candidates,int target)
		{
			int size = candidates.size();
			if(size == 0)
				return ans;
			sort(candidates.begin(),candidates.end());
			for(int i = 0; i < size; ++i)
			{
				if(candidates[i] > target)
					break;
				vector<int> v;
				v.push_back(candidates[i]);
				dfs(v,candidates,target-candidates[i],size);
			}
			return ans;
		}
		void dfs(vector<int> v,vector<int> &candidates,int target,int size)
		{
			if(target == 0)
			{
				ans.push_back(v);
				return;
			}
			int size_v = v.size();
			for(int i = 0;i < size;++i)
			{
				if(candidates[i] < v[size_v - 1])
					continue;
				if(candidates[i] > target)
					return;
				v.push_back(candidates[i]);
				dfs(v,candidates,target-candidates[i],size);
				v.pop_back();
			}
			return;
		}
};

int main()
{
	Solution sol;
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(6);
	v.push_back(7);
	vector<vector<int> > ans = sol.combinationSum(v,8);
	for(int i = 0; i < ans.size(); ++i)
	{
		for(int j = 0; j < ans[i].size(); ++j)
			cout << ans[i][j] << " ";
		cout <<endl;
	}
	return 0;
}



