#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

class Solution
{
	public:
		int divide(int dividend,int divisor)
		{
			int ans = 0;
			bool flag = false;
			if(dividend * divisor < 0)
				flag = true;

			if(dividend < 0)
				dividend *= -1;
			if(divisor < 0)
				divisor *= -1;

			if(dividend < divisor)
				return 0;
			if(dividend == divisor)
			{
				if(flag)
					return -1;
				else
					return 1;
			}

			while(true)
			{
				int tmp = divisor;
				int cnt  = 1;
				while(true)
				{
					tmp = tmp << 1;
					cnt = cnt << 1;
					if(dividend <= tmp)
						break;
				}
				if(dividend == tmp)
				{
					ans += cnt;
					break;
				}
				else
				{
					tmp = tmp >> 1;
					dividend -= tmp;
					ans += cnt / 2;
					if(dividend == divisor) 
					{
						ans++;
						break;
					}
					else if(dividend < divisor)
						break;
				}
			}
			if(flag)
				return -1 * ans;
			else
				return ans;
		}
};
int main()
{
	Solution sol;
	int dividend,divisor;
	cin >> dividend >> divisor;
	cout << sol.divide(dividend,divisor) << endl;
	return 0;
}
