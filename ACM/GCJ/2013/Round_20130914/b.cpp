#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
const double g = 9.8;
const double pi = acos(-1);
const double eps = 1e-10;
int sgn(double a)
{
	return a < -eps ? -1 : a < eps? 0 : 1;
}
int main()
{
	freopen("in","r",stdin);
	freopen("out","w",stdout);
	int T,cases = 0;
	double V,D;
	char output[1024];
	scanf("%d",&T);
	while(T--)
	{
		scanf("%lf%lf",&V,&D);
		double tmp = (D * g) / (V * V);
		if(fabs(tmp - eps) < eps)
		{
			printf("Case #%d: 0.0000000\n",++cases);
			continue;
		}
		double ans = asin(tmp) * 90.0 / pi + eps;
		sprintf(output,"%.7lf\n",ans);
		if(strcmp(output,"-0.0000000") == 0)
			printf("Case #%d: 0.0000000\n",++cases);
		else
			printf("Case #%d: %.7lf\n",++cases,ans);
	}
}

