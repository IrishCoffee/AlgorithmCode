#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
using namespace std;

int trace[1024];
void minCoin(int A[],int n,int k)
{
	int dp[1024];
	memset(dp,1,sizeof(dp));
	memset(trace,0,sizeof(trace));
	dp[0] = 0;
	for(int i = 0; i < k; ++i)
		dp[A[i]] = 1;
	for(int i = 1; i <= n; ++i)
	{
		for(int j = 0; j < k; j++)
		{
			if(A[j] > i)
				break;
			int num = 1 + dp[i - A[j]];
			if(num < dp[i])
			{
				dp[i] = num;
				trace[i] = A[j];
			}
		}
	}
	printf("Min Coin %d : %d Use {",n,dp[n]);
	while(trace[n])
	{
		printf("%d,",trace[n]);
		n -= trace[n];
	}
	printf("%d}\n",n);
	return;

}
int main()
{
	int N,K;
	int coin[1024];
	scanf("%d",&K);
	for(int i = 0; i < K; ++i)
		scanf("%d",&coin[i]);
	scanf("%d",&N);
	for(int i = 1; i <= N; ++i)
		minCoin(coin,i,K);
	return 0;
}

