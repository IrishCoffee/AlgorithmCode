#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

class Solution
{
	public:
		vector<vector<int> > ans;
		vector<vector<int> > combinationSum2(vector<int> &candidates,int target)
		{
			int size = candidates.size();
			if(size == 0)
				return ans;
			sort(candidates.begin(),candidates.end());
			for(int i = 0; i < size; ++i)
			{
				if(candidates[i] > target)
					break;
				if(i > 0 && candidates[i] == candidates[i-1])
					continue;
				vector<int> v;
				v.push_back(candidates[i]);
				dfs(v,i+1,candidates,target-candidates[i],size);
			}
			return ans;
		}
		void dfs(vector<int> v,int next,vector<int> &candidates,int target,int size)
		{
			if(target == 0)
			{
				ans.push_back(v);
				return;
			}
			int size_v = v.size();
			for(int i = next;i < size;++i)
			{
				if(candidates[i] > target)
					return;
				if(i > next && candidates[i] == candidates[i-1])
					continue;
				/*
				if(candidates[i] == v[size_v - 1])
				{
					int cnt1 = 0;
					for(int j = i-1; j>= 0; --j)
					{
						if(candidates[j] != candidates[i])
							break;
						cnt1++;
					}
					int cnt2 = 0;
					for(int j = size_v -1; j >= 0; --j)
					{
						if(candidates[i] != v[j])
							break;
						cnt2++;
					}
					if(cnt1 != cnt2)
						continue;
				}
				*/
				v.push_back(candidates[i]);
				dfs(v,i+1,candidates,target-candidates[i],size);
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
	v.push_back(3);
	v.push_back(3);
	v.push_back(3);
	v.push_back(4);
	vector<vector<int> > ans = sol.combinationSum2(v,4);
	for(int i = 0; i < ans.size(); ++i)
	{
		for(int j = 0; j < ans[i].size(); ++j)
			cout << ans[i][j] << " ";
		cout <<endl;
	}
	return 0;
}



