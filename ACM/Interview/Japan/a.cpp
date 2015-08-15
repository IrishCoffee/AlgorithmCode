#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <cstring>
#include <algorithm>
#include <queue>
#include <map>
#include <stack>
using namespace std;

int main()
{
	int N,M;
	int L,R,K;
	char s[1024];
	char ss[1024];
	scanf("%d%s%d",&N,s,&M);
	while(M--)
	{
		scanf("%d%d%d",&L,&R,&K);
		L--,R--;
		K = K % (R - L + 1);
		strcpy(ss,s);
		for(int i = 0; i < K; ++i)
			s[i + L] = ss[i + R - K + 1];
		for(int i = L + K;i <= R; ++i)
			s[i] = ss[i - K];
	}
	printf("%s\n",s);


	return 0;
}
