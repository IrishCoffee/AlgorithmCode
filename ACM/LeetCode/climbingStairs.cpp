#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

class Solution
{
	public:
		int climbStairs(int n)
		{
			int dp[4096];
			dp[0] = dp[1] = 1;
			for(int i = 2; i <= n; ++i)
				dp[i] = dp[i-1] + dp[i-2];
			return dp[n];
		}
};

int main()
{
	int n;
	cin >> n;
	Solution sol;
	cout << sol.climbStairs(n) << endl;
	return 0;
}
