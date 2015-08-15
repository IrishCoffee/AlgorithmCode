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

class LongWordsDiv2 
{
	public:
	string find(string word) 
	{
		int len = word.size();
		for(int i = 0; i < len; ++i)
		{
			if(word[i] >= 'A' && word[i] <= 'Z')
				continue;
			else
				return "Dislikes";
		}
		for(int i = 1; i < len; ++i)
		{
			if(word[i] == word[i-1])
				return "Dislikes";
		}
		char x,y;
		for(int i = 0;i < 26; ++i)
		{
			x = 'A' + i;
			for(int j = 0; j < 26; ++j)
			{
				y = 'A' + j;
				int cnt = 0;
				char next = x;
				for(int k = 0; k < len; ++k)
				{
					if(word[k] == next)
					{
						if(next == x)
							next = y;
						else 
							next = x;
						cnt++;
					}
				}
				if(cnt >= 4)
					return "Dislikes";
			}
		}
		return "Likes";
	}
};
/*
int main()
{
	LongWordsDiv2 sol;
	string input;
	cin >> input;
	cout << sol.find(input) << endl;
	return 0;
}
*/
