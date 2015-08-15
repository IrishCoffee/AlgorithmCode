#include <iostream>
#include <cstdio>
using namespace std;

class Solution 
{
	public:
		int uniquePaths(int m,int n)
		{
			int dp[128][128];
			memset(dp,0,sizeof(dp));
			dp[1][1] = 1;
			for(int i = 1; i <= m; ++i)
				for(int j = 1; j <= n; ++j)
				{
					if(i == 1 && j == 1)
						continue;
					dp[i][j] = dp[i-1][j] + dp[i][j-1];
				}
			return dp[m][n];
		}
};

int main()
{
	int m,n;
	cin >> m >> n;
	Solution sol;
	cout << sol.uniquePaths(m,n) << endl;
	return 0;
}
