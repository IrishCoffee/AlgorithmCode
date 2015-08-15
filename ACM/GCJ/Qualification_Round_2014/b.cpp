#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
double C,F,X;
const double eps = 1e-6;
double f(double a)
{
	return (C/a + X/(a+F));
}
int main()
{
	freopen("in","r",stdin);
	freopen("out","w",stdout);
	int T,nn = 0;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%lf%lf%lf",&C,&F,&X);
		double ans = 0,rate = 2.0;
		while(true)
		{
			double noBuy = X/rate;
			double buy = f(rate);
			if(noBuy < buy)
			{
				ans += noBuy;
				break;
			}
			else
			{
				ans += C/rate;
				rate += F;
			}
		}
		printf("Case #%d: %.7lf\n",++nn,ans);
	}
}




