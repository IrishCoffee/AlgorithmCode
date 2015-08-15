#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include "Trixel.h"
#include "Cartesian.h"
using namespace std;

int main()
{
	freopen("in","r",stdin);
	double ra,dec;
	Trixel trixel;
	int id = 1;
	while(scanf("%lf%lf",&ra,&dec) == 2)
	{
		Cartesian c(ra,dec);
		printf("%d %lld\n",id++,trixel.CartesianToHid(c,20));
	}
	return 0;
}
