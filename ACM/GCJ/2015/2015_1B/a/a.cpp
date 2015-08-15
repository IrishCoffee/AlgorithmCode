#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int rev(int N)
{
	int num = 0;
	while(N)
	{
		num *= 10;
		num += N % 10;
		N /= 10;
	}
	return num;
}

struct NODE
{
	int num,step;
}tmp;
int main()
{
	freopen("in.txt","r",stdin);
//	freopen("a_out.txt","w",stdout);
	int T;
	int N;
	int cas = 0;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&N);
		queue<NODE> q;
		tmp.num = 0;
		tmp.step = 0;
		q.push(tmp);
		int ans = 0;
		while(true)
		{
			NODE cur = q.front();
			q.pop();
			tmp.step = cur.step + 1;
			
			tmp.num = cur.num + 1;
			if(tmp.num == N)
			{
				ans = tmp.step;
				break;
			}
			q.push(tmp);
			
			tmp.num = rev(cur.num);
			if(tmp.num == N)
			{
				ans = tmp.step;
				break;
			}
			q.push(tmp);
		}

		printf("Case #%d: %d\n",++cas,ans);
	}
	return 0;
}
