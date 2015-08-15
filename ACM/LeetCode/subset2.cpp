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
			if(k > 0 && S[k] == S[k-1])
			{
				int cnt = 0;
				for(int i = k-1; i>= 0; --i)
				{
					if(S[i] == S[k])
						cnt++;
					else
						break;
				}
				int size = v.size();
				int cnt2 = 0;
				for(int i = size - 1;i >= 0; --i)
				{
					if(v[i] != S[k])
						break;
					else
						cnt2++;
				}
				if(cnt != cnt2)
					return;
			}
			v.push_back(S[k]);
			dfs(S,v,k+1);
		}
};

int main()
{
	Solution sol;
	vector<int> s;
	s.push_back(5);
	s.push_back(5);
	s.push_back(5);
	s.push_back(5);
	s.push_back(5);
	vector<vector<int> > v = sol.subsets(s);
	cout << v.size() << endl;
	for(int i = 0; i < v.size(); ++i)
	{
		for(int j = 0; j < v[i].size(); ++j)
			cout << v[i][j] << " ";
		cout << endl;
	}
	return 0;
}


