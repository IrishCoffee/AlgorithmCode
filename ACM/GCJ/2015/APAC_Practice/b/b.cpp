#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <map>
#include <stack>
#include <queue>
#include <cstring>
#include <cmath>
using namespace std;
#define PI 3.1415926535898

int main()
{
	freopen("in","r",stdin);
	freopen("b_out","w",stdout);

	int T,cas,V,D;
	scanf("%d",&T);
	cas = 0;
	while(T--)
	{
		scanf("%d%d",&V,&D);
		double tmp = D * 9.8 / (V* V);
		double asin_tmp = asin(tmp);
		if(tmp > 1.0)
			tmp = 1.0;
		double ans = 0.5 * asin(tmp) / PI;
		ans *= 180.0;
		printf("Case #%d: %.7lf\n",++cas,ans);

	}

	return 0;
}
