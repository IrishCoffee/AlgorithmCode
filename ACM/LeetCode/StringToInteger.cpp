#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

class Solution
{
	public:
		int atoi(const char *str)
		{
			int i = 0,ans = 0;
			bool flag = false,start = false;
			int len = strlen(str);
			for(int i = 0;i < len; ++i)
			{
				if(str[i] == ' ' && !start)
					continue;
				else if(str[i] == ' ')
					break;

				else if(str[i] == '-' && !start)
				{
					flag = true;
					start = true;
					continue;
				}
				else if(str[i] == '-')
					break;

				else if(str[i] == '+' && !start)
				{
					start = true;
					continue;
				}
				else if(str[i] == '+')
					break;

				else if(str[i] >= '0' && str[i] <= '9' && !start)
				{
					start = true;
					ans = ans * 10 + str[i] - '0';
				}
				else if(str[i] >= '0' && str[i] <= '9' && start)
				{
					if(ans > 214748364)
					{
						if(flag)
							return -2147483648;
						else
							return 2147483647;
					}
					else if(ans == 214748364)
					{
						int tmp = str[i] - '0';
						if(tmp >= 7 && flag == false)
							return 2147483647;
						else if(tmp >= 8 && flag)
							return -2147483648;
						else
							ans = ans * 10 + str[i] - '0';
					}
					else
						ans = ans * 10 + str[i] - '0';

				}
				else
					break;
			}
			if(flag)
				ans *= - 1;
			return ans;
		}
};

int main()
{
	Solution sol;
	cout << sol.atoi("2147483648") << endl;
	cout << sol.atoi("-2147483648") << endl;
	cout << sol.atoi("   2147483649") << endl;
	cout << sol.atoi("   2147500000") << endl;
	cout << sol.atoi("   -2147483646") << endl;
	cout << sol.atoi("    -2147483649") << endl;
	cout << sol.atoi("    -+ 2345") << endl;
	cout << sol.atoi("    -- 2345") << endl;


	return 0;
}




