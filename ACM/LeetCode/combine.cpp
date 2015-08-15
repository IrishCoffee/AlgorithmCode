#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
using namespace std;

class Solution
{
	public:
		vector<vector<int> > combine(int n,int k)
		{
			vector<vector<int> > ans;
			vector<int> v;
			dfs(ans,v,1,n,k);
			return ans;
		}
		void dfs(vector<vector<int> > &ans,vector<int> &v,int next,int n,int k)
		{
			if(next > n)
			{
				if(v.size() == 0)
					return;
				next = v.back();
				v.pop_back();
			}
			else
			{
				v.push_back(next);
				if(v.size() == k)
				{
					ans.push_back(v);
					v.pop_back();
				}
			}
			dfs(ans,v,next+1,n,k);
		}
};
int main()
{
	Solution sol;
	int n,k;
	cin >> n >> k;
	vector<vector<int> > ans = sol.combine(n,k);
	int len = ans.size();
	cout << len << endl;
	for(int i = 0; i < len; ++i)
	{
		for(int j = 0; j < k; ++j)
			cout << ans[i][j] << " ";
		cout << endl;
	}
	return 0;
}


