#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <cmath>
using namespace std;

class Solution
{
	public:
		vector<vector<string> > solveNQueens(int n)
		{
			vector<vector<string> > ans;
			if(n == 0)
				return ans;
			int pos[n];
			solve(ans,pos,n,0);
			return ans;
		}
		bool check(int pos[],int row)
		{
			for(int i = 0; i < row; ++i)
				if(pos[i] == pos[row] || fabs(pos[row] - pos[i]) == fabs(row - i))
						return false;
			return true;
		}
		void solve(vector<vector<string> > &ans,int pos[],int n,int row)
		{
			if(row == n)
			{
				vector<string> v;
				for(int i = 0; i < n; ++i)
				{
					string s;
					for(int j = 0; j < n; ++j)
					{
						if(j == pos[i])
							s += 'Q';
						else
							s += '.';
					}
					v.push_back(s);
				}
				ans.push_back(v);
			}
			for(int i = 0; i < n; ++i)
			{
				pos[row] = i;
				if(check(pos,row))
					solve(ans,pos,n,row+1);
			}
			return;
		}
};
int main()
{
	int n;
	cin >> n;
	Solution sol;
	vector<vector<string> > v = sol.solveNQueens(n);
	for(int i = 0; i < v.size(); ++i)
	{
		cout << "\n-----------\n" << endl;
		for(int j = 0; j < n; ++j)
			cout << v[i][j] << endl;
	}
	return 0;
}
