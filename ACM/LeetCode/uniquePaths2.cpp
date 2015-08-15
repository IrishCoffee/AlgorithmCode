#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

class Solution 
{
	public:
		int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid)
		{
			int m = obstacleGrid.size();
			if(m == 0)
				return 0;
			int n = obstacleGrid[0].size();
			if(n == 0)
				return 0;
			if(obstacleGrid[0][0] == 1)
				return 0;

			int dp[128][128];
			memset(dp,0,sizeof(dp));
			dp[1][1] = 1;
			
			for(int i = 1; i <= m; ++i)
				for(int j = 1; j <= n; ++j)
				{
					if(i == 1 && j == 1)
						continue;
					if(obstacleGrid[i-1][j-1] == 1)
						continue;
					dp[i][j] = dp[i-1][j] + dp[i][j-1];
				}
			return dp[m][n];
		}
};

int main()
{
	int num[5][5] = {{0,0,0},{0,1,0},{0,0,0}};
	vector<vector<int> >v;
	for(int i = 0; i < 3; ++i)
	{
		vector<int> tmp;
		for(int j = 0;j < 3; ++j)
			tmp.push_back(num[i][j]);
		v.push_back(tmp);
	}
	Solution sol;
	cout << sol.uniquePathsWithObstacles(v) << endl;
	return 0;
}
