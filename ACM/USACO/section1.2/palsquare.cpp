/*
ID: irishco1
PROG: palsquare
LANG: C++
*/
#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;

int square[301];
int main()
{
	freopen("palsquare.in","r",stdin);
	freopen("palsquare.out","w",stdout);
	for(int i = 0; i <= 300; ++i)
		square[i] = i*i;
	int b;
	scanf("%d",&b);
	for(int i = 1; i <= 300; ++i)
	{
		int tmp = square[i];
		char number[1000000];
		int cnt = 0;
		while(tmp)
		{
			int mod = tmp % b;
			if(mod >= 10)
				number[cnt++] = mod - 10 + 'A';
			else
				number[cnt++] = mod + '0';
			tmp /= b;
		}
		bool flag = true;
		for(int j = 0; j < cnt/2; ++j)
		{
			if(number[j] != number[cnt - 1 - j])
			{
				flag = false;
				break;
			}
		}
		if(flag)
		{
			int cnt1 = 0;
			tmp = i;
			char num[100000];
			while(tmp)
			{
				int mod = tmp % b;
				if(mod >= 10)
					num[cnt1++] = mod - 10 + 'A';
				else
					num[cnt1++] = mod + '0';
				tmp /= b;
			}
			for(int j = cnt1 - 1; j >= 0; --j)
				printf("%c",num[j]);
			printf(" ");
			for(int j = cnt-1;j >= 0; --j)
				printf("%c",number[j]);
			printf("\n");
		}
	}
}



