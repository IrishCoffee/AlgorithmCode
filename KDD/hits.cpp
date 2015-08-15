#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

int M[4][4] = {{0,1,1,0},{0,0,0,0},{0,0,0,1},{0,0,1,0}};
int Mt[4][4] = {{0,0,0,0},{1,0,0,0},{1,0,0,1},{0,0,1,0}};

int MMt[4][4];
int MtM[4][4];

double h[1000][4],hn[1000][4],a[1000][4],an[1000][4];
int main()
{
	for(int i = 0; i < 4; ++i)
	{
		for(int j = 0; j < 4; ++j)
		{
			int tmp1 = 0,tmp2 = 0;
			for(int k = 0; k < 4; ++k)
			{
				tmp1 += M[i][k] * Mt[k][j];
				tmp2 += Mt[i][k] * M[k][j];
			}
			MMt[i][j] = tmp1;
			MtM[i][j] = tmp2;
		}
	}
	for(int i = 0; i < 4; ++i)
		h[i][0] = hn[i][0] = a[i][0] = an[i][0] = 1;
	int i = 1;
	for(;; ++i)
	{
		for(int j = 0; j < 4; ++j)
		{
			double tmp = 0;
			for(int k = 0; k < 4; ++k)
				tmp += MMt[j][k] * hn[k][i-1];
			h[j][i] = tmp;
		}
		printf("%d %.3lf %.3lf %.3lf %.3lf\n",i,h[0][i],h[1][i],h[2][i],h[3][i]);
		double sum = 0;
		for(int j = 0; j < 4; ++j)
			sum += h[j][i];
		for(int j = 0; j < 4; ++j)
			hn[j][i] = h[j][i] * 4.0 / sum;
		bool flag = true;
		for(int j = 0; j < 4; ++j)
		{
			if((hn[j][i]- hn[j][i-1]) > 0.0001 || (hn[j][i] - hn[j][i-1]) < -0.0001)
			{
				flag = false;
				break;
			}
		}
		if(flag)
		{
			cout << "final " << endl;
			printf("%d %.3lf %.3lf %.3lf %.3lf\n",i,h[0][i],h[1][i],h[2][i],h[3][i]);
			printf("%d %.3lf %.3lf %.3lf %.3lf\n",i,hn[0][i],hn[1][i],hn[2][i],hn[3][i]);
			break;
		}
	}

    printf("\n\n a \n");
	i = 1;
	for(;; ++i)
	{
		for(int j = 0; j < 4; ++j)
		{
			double tmp = 0;
			for(int k = 0; k < 4; ++k)
				tmp += MtM[j][k] * an[k][i-1];
			a[j][i] = tmp;
		}
		printf("%d %.3lf %.3lf %.3lf %.3lf\n",i,a[0][i],a[1][i],a[2][i],a[3][i]);
		double sum = 0;
		for(int j = 0; j < 4; ++j)
			sum += a[j][i];
		for(int j = 0; j < 4; ++j)
			an[j][i] = a[j][i] * 4.0 / sum;
		bool flag = true;
		for(int j = 0; j < 4; ++j)
		{
			if((an[j][i]- an[j][i-1]) > 0.0001 || (an[j][i] - an[j][i-1]) < -0.0001)
			{
				flag = false;
				break;
			}
		}
		if(flag)
		{
			cout << "final " << endl;
			printf("%d %.3lf %.3lf %.3lf %.3lf\n",i,a[0][i],a[1][i],a[2][i],a[3][i]);
			printf("%d %.3lf %.3lf %.3lf %.3lf\n",i,an[0][i],an[1][i],an[2][i],an[3][i]);
			break;
		}
	}
	return 0;
}


