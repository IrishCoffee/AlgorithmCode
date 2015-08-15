#include <iostream>
#include <string>
#include <cstdio>
using namespace std;

class Solution
{
	public:
		string addBinary(string a,string b)
		{
			int size1 = a.size();
			int size2 = b.size();
			string ans;
			int i,j;
			int tmp = 0;
			for(i = size1 - 1,j = size2 - 1; i>= 0 &&  j >= 0; --i,--j)
			{
				int m = a[i] - '0';
				int n = b[j] - '0';
				ans += '0' + (m + n + tmp) % 2;
				tmp = (m + n + tmp) / 2;
			}
			if(i >= 0)
			{
				while(i >= 0)
				{
					int m = a[i] - '0';
					ans += '0' + ((m + tmp) % 2);
					tmp = (m + tmp) / 2;
					--i;
				}
			}
			if(j >= 0)
			{
				while(j >= 0)
				{
					int m = b[j] - '0';
					ans += '0' + ((m + tmp) % 2);
					tmp = (m + tmp) / 2;
					--j;
				}
			}
			if(tmp != 0)
				ans += '1';
			reverse(ans.begin(),ans.end());
			return ans;
		}
};

int main()
{
	string a,b;
	cin >> a >> b;
	Solution sol;
	cout << sol.addBinary(a,b) << endl;
}
