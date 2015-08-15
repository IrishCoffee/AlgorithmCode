#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

class Solution
{
	public:
		int jump(int A[],int n)
		{
			int dp[300000];
			dp[0] = 0;
			for(int i = 0; i < n; ++i)
			{
				for(int j = 1; j <= A[i]; ++j)
				{
					if(dp[i+j] == 0)
						dp[i+j] = dp[i] + 1;
					else
						dp[i+j] = min(dp[i]+1,dp[i+j]);
					if(i+j == A[n-1])
						return dp[i+j];
				}
			}
		}
};

int main()
{
	int A[64];
	int n;
	cin >> n;
	for(int i = 0; i < n; ++i)
		cin >> A[i];
	Solution sol;
	cout << sol.jump(A,n) << endl;
}
