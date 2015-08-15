#include <iostream>
#include <stack>
#include <string>
#include <vector>
using namespace std;

class Solution
{
	public:
		int evalRPN(vector<string> & tokens)
		{
			stack<int> s;
			int size = tokens.size();
			for(int i = 0; i < size; ++i)
			{
				if(tokens[i][0] == '+')
				{
					int a = s.top();
					s.pop();
					a += s.top();
					s.pop();
					s.push(a);
				}
				else if(tokens[i][0] == '-' && tokens[i].size() == 1)
				{
					int a = s.top();
					s.pop();
					a = s.top() - a;
					s.pop();
					s.push(a);
				}
				else if(tokens[i][0] == '*')
				{
					int a = s.top();
					s.pop();
					a *= s.top();
					s.pop();
					s.push(a);
				}
				else if(tokens[i][0] == '/')
				{
					int a = s.top();
					s.pop();
					a = s.top() / a;
					s.pop();
					s.push(a);
				}
				else
					s.push(stoi(tokens[i]));
			}
			return s.top();
		}
};

int main()
{
	vector<string> v;
	v.push_back("-1");
	v.push_back("1");
	v.push_back("*");
	v.push_back("-1");
	v.push_back("+");
	Solution sol;
	cout << sol.evalRPN(v) << endl;
}
