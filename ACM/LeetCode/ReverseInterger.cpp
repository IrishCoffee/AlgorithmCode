#include <iostream>
#include <cstdio>
using namespace std;

class Solution
{
	public:
		int reverse(int x)
		{
			int ans = 0;
			bool flag = false;
			if(x < 0)
			{
				flag = true;
				x *= -1;
			}
			while(x > 0)
			{
				ans = ans * 10 + x % 10;
				x /= 10;
			}
			if(flag)
				ans *= -1;
			return ans;
		}
};

int main()
{
	Solution sol;
	cout << sol.reverse(123) << endl;
	cout << sol.reverse(-123) << endl;
	return 0;
}
