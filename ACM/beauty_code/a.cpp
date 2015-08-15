#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iomanip>
#include <cstdlib>
using namespace std;

int main()
{
	char f[1024],c[1024],image[1024];
	int T,nn = 0;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%s%s%s",f,c,image);
		double focal = atof(f);
		double ccd = atof(c);
		double ima = atof(image);
		int len = strlen(f);
		if(f[len-2] == 'd') focal *= 100;
		if(f[len-2] == 'c') focal *= 10;
		if(f[len-2] == 'u') focal *= 0.001;
		if(f[len-2] == 'n') focal *= 0.000001;
		if(f[len-2] >= '0' && f[len-2] <= '9') focal *= 1000;
		len = strlen(c);
		if(c[len-2] == 'd') ccd *= 100;
		if(c[len-2] == 'c') ccd *= 10;
		if(c[len-2] == 'u') ccd *= 0.001;
		if(c[len-2] == 'n') ccd *= 0.000001;
		if(c[len-2] >= '0' && c[len-2] <= '9') ccd *= 1000;
		double ans = ima * focal / ccd;
		cout << "Case " << ++nn << ": " << fixed << setprecision(2) << ans << "px" << endl;
	}
}


