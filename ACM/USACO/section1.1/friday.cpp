/*
ID: irishco1
PROG: friday
LANG: C++
*/
#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
using namespace std;
int count_days[7];
int days[2][12] = {{31,28,31,30,31,30,31,31,30,31,30,31},
	{31,29,31,30,31,30,31,31,30,31,30,31}};
int is_leapYear(int year)
{
	if((year % 4 == 0 && year % 100 != 0 ) || year % 400 == 0)
		return 1;
	return 0;
}
int main()
{
//	freopen("friday.in","r",stdin);
//	freopen("friday.out","w",stdout);
	memset(count_days,0,sizeof(count_days));
	int N,year = 1900;
	int last_month,tmp;
	scanf("%d",&N);
	for(int i = 0; i < N;++i)
	{
		int flag = is_leapYear(year);
		for(int j = 0; j < 12; ++j)
		{
			if(year == 1900 && j == 0)
			{
				count_days[6]++;
				last_month = 0;
				tmp = 6;
				continue;
			}
			tmp = (tmp + days[flag][last_month]) % 7;
			count_days[tmp]++;
			last_month = (++last_month) % 12;
	//		printf("Year:%d current_month: %d tmp: %d\n",year,last_month+1,tmp);
		}
		year++;
	}
	printf("%d %d %d %d %d %d %d\n",count_days[6],count_days[0],count_days[1],count_days[2],count_days[3],count_days[4],count_days[5]);
	return 0;
}


