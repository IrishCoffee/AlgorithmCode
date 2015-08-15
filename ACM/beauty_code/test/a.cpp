#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
	double t[7] = {0.03,0.1,0.2,0.25,0.3,0.35,0.45};
	double tmp[6],pre[6];
	tmp[0] = 1500 * 0.03;
	tmp[1] = (4500 - 1500) * 0.1;
	tmp[2] = 4500 * 0.2;
	tmp[3] = (35000 - 9000) * 0.25;
	tmp[4] = (20000) * 0.3;
	tmp[5] = (80000 - 55000) * 0.35;
	
	pre[0] = tmp[0];
	for(int i = 1;  i < 6; ++i)
		pre[i] = pre[i-1] + tmp[i];
	
	//	for(int i = 0; i < 6; ++i)
	//		cout << tmp[i] << " " << pre[i] << endl;

	double tex,ans = 0;
	cin >> tex;
	for(int i = 5; i >= 0; --i)
	{
		if(tex >= pre[i])
		{
			double tmp = (tex - pre[i]) * 1.0 / t[i+1];
			ans += tmp;
			tex -= tmp * t[i+1];
			//	cout << i << " " << tex << " " << ans * t[i+1] << " " << ans << endl;
		}
	}
	ans += tex / 0.03;
	printf("%d\n",(int)ans + 3500);
}
