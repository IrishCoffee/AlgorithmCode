#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

bool flag[1024];
int matrix[1024][1024];
bool check_flag(int n)
{
	for(int i = 1; i <= n; ++i)
		if(!flag[i])
			return false;
	return true;
}

int main()
{
	freopen("input","r",stdin);
	freopen("out","w",stdout);
	int T,N;
	int cases = 0;
	scanf("%d",&T);
	while(T--)
	{
		bool ff = true;
		scanf("%d",&N);
		for(int i = 0; i < N*N; ++i)
			for(int j = 0; j < N*N; ++j)
				scanf("%d",&matrix[i][j]);
		//check row
		for(int i = 0; i < N*N & ff;++i)
		{
			memset(flag,false,sizeof(flag));
			for(int j = 0; j < N*N & ff;++j)
				flag[matrix[i][j]] = true;
			if(!check_flag(N*N))
			{
				ff = false;
				break;
			}
		}
		for(int i = 0; i < N*N & ff;++i)
		{
			memset(flag,false,sizeof(flag));
			for(int j = 0; j < N*N & ff;++j)
				flag[matrix[j][i]] = true;
			if(!check_flag(N*N))
			{
				ff = false;
				break;
			}
		}

		for(int i = 0; i < N*N & ff; i += N)
		{
			for(int j = 0; j < N*N & ff;j += N)
			{
				memset(flag,false,sizeof(flag));
				for(int p = i; p < i + N & ff; ++p)
					for(int q = j; q < j + N & ff; ++q)
						flag[matrix[p][q]] = true;
				if(!check_flag(N*N))
				{
					ff = false;
					break;
				}
			}
		}
		if(!ff)
			printf("Case #%d: No\n",++cases);
		else 
			printf("Case #%d: Yes\n",++cases);
	}
	return 0;
}
