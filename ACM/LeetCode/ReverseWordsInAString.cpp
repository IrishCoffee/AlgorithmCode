#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
using namespace std;

class Solution
{
	public:
		void reverseWords(string &s)
		{
			char ans[1024];
			int end = s.size();
			int flag = 0;
			end--;
			while(end >= 0 && s[end] == ' ')
				--end;
			if(end == -1)
			{
				s = "";
				return;
			}
			for(int start = end; start >= 0; --start)
			{
				if(s[start] == ' ')
				{
					for(int i = start + 1; i <= end; ++i)
						ans[flag++] = s[i];
					ans[flag++] = " ";
					while(start >= 0 && s[start] == ' ')
						start--;
					end = start;
				}
				if(end ==

			
		}
};
int main()
{
	Solution sol;
	string s = "Sky is Blue";
	sol.reverseWords(s);
	cout << s << endl;
	s = "The Sky is Blue";
	sol.reverseWords(s);
	cout << s << endl;
	s = "12345";
	sol.reverseWords(s);
	cout << s << endl;
	s = " 12345 ";
	sol.reverseWords(s);
	cout << s << endl;
    s = "   The   sky     sky   sky   ";
	sol.reverseWords(s);
	cout << s << endl;
	s = " 1";
	sol.reverseWords(s);
	cout << s << endl;
	s = "    a    ";
	sol.reverseWords(s);
	cout << s << endl;
	return 0;
}
