#include <iostream>
#include <cstdio>
#include <cstring>
#include <cctype>
using namespace std;

class Solution
{
	public:
		int lengthOfLastWord(const char *s)
		{
			if(s == NULL || s == '\0')
				return 0;
			int ans = 0;
			int i = 0;
			while(*(s + i) != '\0')
			{
				if(isspace(*(s + i)))
					ans = 0;
				else
					ans++;
				i++;
			}
			return ans;
		}
};

int main()
{
	Solution sol;
	char s[1024];
	gets(s);
	cout << sol.lengthOfLastWord(s) << endl;
	return 0;
}
