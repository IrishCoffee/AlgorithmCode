#include <iostream>
#include <string>
#include <cmath>
using namespace std;

class Solution
{
	public:
		string getPermutation(int n,int k)
		{
			string s;
			int num[10];
			num[1] = 1;
			bool flag[10];
			memset(flag,true,sizeof(flag));
			for(int i = 2;i <= n; ++i)
				num[i] = i * num[i-1];
			for(int i = n-1; i > 0; --i)
			{
				int current_big = ceil(k * 1.0 / num[i]);
				int tmp = 0;
				for(int j = 1; j <= n; ++j)
				{
					if(flag[j])
						tmp++;
					if(tmp == current_big)
					{
						flag[j] = false;
						s += '0' + j;
						break;
					}
				}
				k -= num[i] * (current_big - 1);
			}
			for(int i = 1; i <= n; ++i)
			{
				if(flag[i])
				{
					s += '0' + i;
					break;
				}
			}
			return s;
		}
};

int main()
{
	Solution sol;
	int n = 5;
	for(int i = 1;i <= 120; ++i)
		cout << sol.getPermutation(n,i) << endl;
	return 0;
}


