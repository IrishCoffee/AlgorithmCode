/*
ID: irishco1
PROG: beads
LANG: C++
 */
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

char necklace[360];
int flag[360];
int main()
{
	freopen("beads.in","r",stdin);
	freopen("beads.out","w",stdout);
	int N;
	scanf("%d%s",&N,necklace);
	int ans = 0;
	memset(flag,-1,sizeof(flag));
	for(int i = 0; i < N; ++i)
	{
		int tmp = 1;
		bool has_changed = false;
		flag[i] = i;
		int j = i + 1;
		if(j == N)
			j = 0;
		for(;j < N; ++j)//from left to right
		{
			if(flag[j] == i)
				break;
			if(necklace[i] == 'w')
			{
				necklace[i] = necklace[j];
				tmp++;
				flag[j] = i;
				has_changed = true;
			}
			else if(necklace[j] == necklace[i] || necklace[j] == 'w')
			{
				tmp++;
				flag[j] = i;
			}
			else
				break;
			if(j == N - 1)
				j = -1;
		}
		if(has_changed)
			necklace[i] == 'w';
		j = i-1;
		if(j < 0)
			j = N - 1;
		int begin_flag = j;
		has_changed = false;
		for(;j >= 0; --j)
		{
			if(flag[j] == i)
				break;
			if(necklace[begin_flag] == 'w')
			{
				necklace[begin_flag] = necklace[j];
				tmp++;
				flag[j] = i;
				has_changed = true;
			}
			else if(necklace[j] == necklace[begin_flag] || necklace[j] == 'w')
			{
				tmp++;
				flag[j] = i;
			}
			else
				break;
			if(j == 0)
				j = N;
		}
		if(has_changed)
			necklace[begin_flag] == 'w';
		if(ans < tmp)
			ans = tmp;
	//	printf("i %d tmp %d\n",i,tmp);
	}
	printf("%d\n",ans);
	return 0;
}




