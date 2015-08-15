#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;

class Solution
{
	public:
		int minPathSum(vector<vector<int> > & grid)
		{
			int dp[100][100];
			int r = grid.size();
			if(r == 0) return 0;
			int c = grid[0].size();
			if(c == 0) return 0;
			for(int i = 0; i < r; ++i)
			{
				for(int j = 0; j < c; ++j)
				{
					if(i == 0 && j == 0) dp[i][j] = grid[i][j];
					else if(i == 0) dp[i][j] = dp[i][j-1] + grid[i][j];//only from left
					else if(j == 0) dp[i][j] = dp[i-1][j] + grid[i][j];//only from right
					else dp[i][j] = min(dp[i-1][j],dp[i][j-1]) + grid[i][j];
				}
			}
			return dp[r-1][c-1];
		}
};

int main()
{
	vector<vector<int> > v;
	vector<int> vv;
	vv.push_back(0);
	v.push_back(vv);
	Solution sol;
	cout << sol.minPathSum(v) << endl;
	return 0;
}

