#include <iostream>
#include <cstdio>
#include <ctime>
#include <cstdlib>
using namespace std;

int num[16];

int main()
{
	srand((int)time(NULL));
	for(int i = 0;i < 16; ++i)
		num[i] = rand() % 100;
	int max = -1;
	int max2 = -1;
	for(int i = 0; i < 16; ++i)
	{
		if(max == -1)
			max = num[i];
		else if(max < num[i])
		{
			max2 = max;
			max = num[i];
		}
		else if(max == num[i])
			max2 = num[i];
		else 
		{
			if(max2 == -1)
				max2 = num[i];
			else if(max2 < num[i])
				max2 = num[i];
		}
	}
	for(int i = 0; i < 16; ++i)
		printf("%3d ",num[i]);
	printf("\n%d\n",max2);
	return 0;
}
