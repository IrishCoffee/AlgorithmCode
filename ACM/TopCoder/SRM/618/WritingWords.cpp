// BEGIN CUT HERE

// END CUT HERE
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <stack>
using namespace std;

class WritingWords 
{
	public:
	int write(string word) 
	{
		int len = word.size();
		int ans = 0;
		for(int i = 0; i < len; ++i)
			ans += word[i] - 'A' + 1;
		return ans;
	}
};
/*
int main()
{
	WritingWords sol;
	string word = "topcoder";
	cout << sol.write(word) << endl;
	return 0;
}
*/
