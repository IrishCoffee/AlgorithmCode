#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

class Solution
{
	public:
		bool isPalindrome(int x)
		{
			if(x < 0)
				return false;
			int tmp = x;
			int len = 1;
			while(tmp >= 10)
			{
				len *= 10;
				tmp /= 10;
			}
			while(x > 0)
			{
				if(x / len != x % 10)
					return false;
				x -= len * (x / len);
				x /= 10;
				len /= 100;
			}
			return true;
		}
};
int main()
{
	Solution sol;
	cout << sol.isPalindrome(1000000001) << endl;
	cout << sol.isPalindrome(-2147483648) << endl;
	cout << sol.isPalindrome(2147483647) << endl;
	return 0;
}



