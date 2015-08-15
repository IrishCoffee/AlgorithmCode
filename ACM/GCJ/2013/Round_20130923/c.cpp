#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int order[1024];
int bobs[1024];
int alex[1024];
int main()
{
	freopen("in","r",stdin);
	freopen("out","w",stdout);
	int T,N;
	int cases = 0;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&N);
		for(int i = 0; i < N; ++i)
			scanf("%d",&order[i]);
		printf("Case #%d: ",++cases); 
		int flag_b = 0,flag_a = 0;
		for(int i = 0; i < N; ++i)
		{
			if(order[i] % 2 == 0)
				bobs[flag_b++] = order[i];
			else
				alex[flag_a++] = order[i];
		}
		sort(bobs,bobs + flag_b);
		sort(alex,alex + flag_a);
		int id_a = 0;
		for(int i = 0; i < N; ++i)
		{
			if(order[i] % 2 == 0)
				printf("%d",bobs[--flag_b]);
			else
				printf("%d",alex[id_a++]);
			if(i != N - 1)
				printf(" ");
		}
		printf("\n");

	}
}

