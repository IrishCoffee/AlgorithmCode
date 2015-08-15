#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

int main()
{
	freopen("in.txt","r",stdin);
	freopen("a_out.txt","w",stdout);
	int T;
	int cas = 0;
	int Sm;
	char input[1024];
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%s",&Sm,input);
		int current = 0;
		int ans = 0;
		for(int i = 0; i <= Sm; ++i)
		{
			if(current < i)
			{
				int delta = i - current;
				current += delta; //add aditional audience
				ans += delta;
			}
			current += input[i] - '0';
		}
		printf("Case #%d: %d\n",++cas,ans);
	}
	return 0;
}
