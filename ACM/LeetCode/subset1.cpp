#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
class Solution
{
	public:
		vector<vector<int> > ans;
		vector<vector<int> > subsets(vector<int> &S)
		{
			sort(S.begin(),S.end());
			vector<int> v;
			dfs(S,v,0);
			return ans;
		}
		void dfs(vector<int> &S,vector<int> v,int k)
		{
			if(k == S.size())
			{
				ans.push_back(v);
				return;
			}
			dfs(S,v,k+1);
			v.push_back(S[k]);
			dfs(S,v,k+1);
		}
};

int main()
{
	Solution sol;
	vector<int> s;
	s.push_back(1);
	s.push_back(2);
	s.push_back(3);
	s.push_back(4);
	vector<vector<int> > v = sol.subsets(s);
	for(int i = 0; i < v.size(); ++i)
	{
		for(int j = 0; j < v[i].size(); ++j)
			cout << v[i][j] << " ";
		cout << endl;
	}
	return 0;
}

		
