#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iomanip>
#include <cstdlib>
#include <algorithm>
using namespace std;
int n,T;
const double eps = 1e-8;
struct NODE
{
	int x,y;
}pos[100005];

double sum(double x)
{
	double ans = 0;
	for(int i = 0; i < n; ++i)
		ans += sqrt(pos[i].x * pos[i].x * 1.0+ pos[i].y * pos[i].y * 1.0 + x * x - 2.0 * x * pos[i].x);
	return ans;
}
bool cmp(NODE a,NODE b)
{
	if(a.x < b.x)
		return true;
	return false;
}
int main()
{
	int nn = 0;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(int i = 0; i < n; ++i)
			scanf("%d%d",&pos[i].x,&pos[i].y);
		sort(pos,pos+n,cmp);
		double begin = pos[0].x * 1.0;
		double end = pos[n-1].x * 1.0;
		double tmp = 0,x0;
		bool flag = true;
		while(true)
		{
			double mid = (begin + end) * 0.5;
			double sum1 = sum(begin);
			double sum2 = sum(end);
			double sum0 = sum(mid);
			if(flag)
			{
				flag = false;
				x0 = mid;
			}
			else if(!flag && fabs(x0 - mid) < eps)
			{
				x0 = mid;
				break;
			}
			if(sum1 <  sum2)
				end = mid;
			else
				begin = mid;
			x0 = mid;
		}
		printf("Case %d: %.7lf\n",++nn,x0);
	}
}


