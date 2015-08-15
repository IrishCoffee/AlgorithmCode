/*
ID: irishco1
PROG: dualpal
LANG: C++
*/
#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;

bool test(int num)
{
	int ans = 0;
	for(int b = 2; b <= 10; ++b)
	{
		int cnt = 0;
		int number[100000];
		int tmp = num;
		while(tmp)
		{
			number[cnt++] = tmp % b;
			tmp /= b;
		}
		bool flag = true;
		for(int i = 0; i < cnt/2; ++i)
		{
			if(number[i] != number[cnt - 1 - i])
			{
				flag = false;
				break;
			}
		}
		if(flag)
			ans++;
		if(ans >= 2)
			return true;
	}
	return false;
}



int main()
{
	freopen("dualpal.in","r",stdin);
	freopen("dualpal.out","w",stdout);
	int N,S;
	scanf("%d%d",&N,&S);
	int cnt = 0;
	for(int i = S+1;;++i)
	{
		if(test(i))
		{
			printf("%d\n",i);
			cnt++;
		}
		if(cnt == N)
			break;
	}

}



