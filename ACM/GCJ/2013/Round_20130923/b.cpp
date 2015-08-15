#include <iostream>
#include <cstdio>
#include <algorithm>
#include <stack>
using namespace std;
unsigned long long tmp[128];
int flag[128];
unsigned long long ans_p,ans_q;
int num;
void solve1(int id,unsigned long long p,unsigned long long q)
{
	if(id < 0)
	{
		ans_p = p;
		ans_q = q;
		return;
	}
	else if(tmp[id] % 2 == 0)
		solve1(id-1,p,p+q);
	else
		solve1(id-1,p+q,q);
}
void solve2(int id,unsigned long long p,unsigned long long q)
{
	if(p == 1 && q == 1)
	{
		num = id;
		return;
	}
	if(p > q)
	{
		flag[id] = 1;
		solve2(id+1,p-q,q);
	}
	else
	{
		flag[id] = 0;
		solve2(id+1,p,q-p);
	}
}
int main()
{
//	freopen("in","r",stdin);
//	freopen("out","w",stdout);
	unsigned long long n,nn,p,q;
	int T,id,pro_id;
	int cases = 0;
	scanf("%d",&T);
	while(T--)
	{
		id = 0;
		scanf("%d",&pro_id);
		if(pro_id == 1)
		{	
			scanf("%llu",&n);
			nn = n;
			while(nn)
			{
				tmp[id++] = nn;
				nn /= 2;
			}
			solve1(id-2,1,1);
			printf("Case #%d: %llu %llu\n",++cases,ans_p,ans_q);
		}
		else
		{
			scanf("%llu%llu",&p,&q);
			solve2(0,p,q);
			unsigned long long ans = 1;
			for(int i = num-1; i >= 0; --i)
			{
				if(flag[i])
					ans = ans*2 + 1;
				else
					ans *= 2;
			}
			printf("Case #%d: %llu\n",++cases,ans);
		}
	}
	return 0;
}

