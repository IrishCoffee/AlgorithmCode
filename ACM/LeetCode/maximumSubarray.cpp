#include <iostream>
#include <cmath>
using namespace std;
class Solution
{
	public:
		int maxSubArray(int A[],int n)
		{
			int dp[4096];
			dp[0] = A[0];
			int ans = A[0];
			for(int i = 1; i < n; ++i)
			{
				dp[i] = max(dp[i-1],A[i-1]) + A[i];
				ans = max(max(dp[i],A[i]),ans);
			}
			return ans;
		}
};

int main()
{
	int n;
	cin >> n;
	int A[16];
	for(int i = 0; i < n; ++i)
		cin >> A[i];
	Solution sol;
	cout << sol.maxSubArray(A,n) << endl;
	return 0;
}
