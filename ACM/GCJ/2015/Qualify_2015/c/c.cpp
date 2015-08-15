#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;
int mat[5][5] = {{0,0,0,0,0},{0,1,2,3,4},{0,2,-1,4,-3},{0,3,-4,-1,2},{0,4,3,-2,-1}};
int abs(int x)
{
	if(x > 0)
		return x;
	return -1 * x;
}
int check(int m,int n,char s[])
{
	int cur = 1;
	for(int i = m; i <= n;++i)
	{
		int tmp = mat[abs(cur)][s[i] - 'i' + 2];
		if(cur < 0)
			tmp *= -1;
		cur = tmp;
	}
	return cur;
}

int get_last(int second,int cur)
{
	for(int i = 1; i <= 4; ++i)
		if(mat[i][cur] == second)
			return i;
	for(int i = 1; i <= 4; ++i)
		if(mat[i][cur] == -1 * second)
			return -1 * i;

}
int main()
{
	freopen("in.txt","r",stdin);
	freopen("c_out.txt","w",stdout);
	int T;
	int cas = 0;
	int L,X;
	bool ok = true;
	char s[10005];
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d%s",&L,&X,s);
		int cur = L;
		for(int i = 1; i < X; ++i)
		{
			for(int j = 0; j < L; ++j)
				s[cur++] = s[j];
		}
		int len = X * L;
		ok = false;
		int first = 1;
		int second = 1;
		int third = 1;
		for(int i = 0; i < len - 2; ++i)
		{
			cur = mat[abs(first)][s[i] - 'i' + 2];
			if(first < 0)
				first = -1 * cur;
			else
				first = cur;

			if(first != 2)
				continue;

			third = 1;
			second = check(i+1,len-1,s);
			for(int j = len - 1; j > i; --j)
			{
				cur = mat[s[j] - 'i' + 2][abs(third)];
				if(third < 0)
					third = -1 * cur;
				else
					third = cur;
				second = get_last(second,s[j] - 'i' + 2);
				if(second == 3 && third == 4)
				{
					ok = true;
					break;
				}
			}
			if(ok)
				break;
		}
		if(ok)
			printf("Case #%d: YES\n",++cas);
		else
			printf("Case #%d: NO\n",++cas);
	}
	return 0;
}
