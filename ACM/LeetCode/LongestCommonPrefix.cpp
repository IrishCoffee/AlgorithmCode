#include <iostream>
#include <cstdio>
#include <string>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
	public:
		string longestCommonPrefix(vector<string> &strs)
		{
			char ans[100000];
			int num = strs.size();
			if(num == 0)
				return string("");
			int min_len  = strs[0].length();
			for(int i = 1; i < num; ++i)
				min_len = min(min_len,(int)strs[i].length());
			int i;
			for(i = 0; i < min_len; ++i)
			{
				char tmp = strs[0][i];
				bool flag = true;
				for(int j = 1; j < num; ++j)
				{
					if(strs[j][i] != tmp)
					{
						flag = false;
						break;
					}
				}
				if(flag)
					ans[i] = tmp;
				else
					break;
			}
			ans[i] = '\0';
			return string(ans);
		}
};

int main()
{
	vector<string> strs;
	strs.push_back("");
	//	strs.push_back("abc");
	//	strs.push_back("abefed");
	//	strs.push_back("bcde");
	Solution sol;
	cout << sol.longestCommonPrefix(strs) << endl;
	return 0;
}




