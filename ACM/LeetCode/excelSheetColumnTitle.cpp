#include <iostream>
#include <cstring>
#include <string>
#include <iterator>
#include <vector>
using namespace std;

class Solution
{
	public:
		string convertToTitle(int n)
		{
			string ans;
			while(n)
			{
				int now = n % 26;
				if(now == 0 && n >= 26)
					now = 26;
				ans += now + 'A' - 1;
				n = (n - now) / 26;
			}
			reverse(ans.begin(),ans.end());
			return ans;
		}
};

int main()
{
	Solution sol;
	for(int i = 300; i <= 307; ++i)
		cout << i << " " << sol.convertToTitle(i) << endl;
	return 0;
}
