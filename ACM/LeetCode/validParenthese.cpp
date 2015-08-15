#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <stack>
using namespace std;

class Solution
{
	public:
		bool isValid(string s)
		{
			stack<char> q;
			int len = s.size();
			for(int i = 0; i < len; ++i)
			{
				if(s[i] == '[' || s[i] == '{' || s[i] == '(')
					q.push(s[i]);
				else
				{
					if(q.empty())
						return false;
					char c = q.top();
					if((s[i] == ']' && c == '[') || (s[i] == ')' && c == '(') || (s[i] == '}' && c == '{'))
						q.pop();
					else
						return false;
				}
			}
			if(q.empty())
				return true;
			else
				return false;
		}
};

int main()
{
	Solution sol;
	string s;
	cin >> s;
	cout << sol.isValid(s) << endl;
}
