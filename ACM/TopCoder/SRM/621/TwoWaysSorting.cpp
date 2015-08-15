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

class TwoWaysSorting 
{
	public:
	string sortingMethod(vector <string> stringList) 
	{
		int len[64];
		int size = stringList.size();
		for(int i = 0; i < size; ++i)
			len[i] = stringList[i].length();
		bool flag1 = true,flag2 = true;
		for(int i = 1; i < size; ++i)
			if(len[i] <= len[i-1])
			{
				flag2 = false;
				break;
			}
		for(int i = 1; i < size && flag1; ++i)
		{
			bool diff = false;
			int min_len = min(len[i],len[i-1]);
			for(int j = 0; j < min_len; ++j)
			{
				if(stringList[i-1][j] > stringList[i][j])
				{
					flag1 = false;
					break;
				}
				else if(stringList[i-1][j] < stringList[i][j])
				{
					diff = true;
					break;
				}
			}
			if(!diff && len[i-1] > len[i])
				flag1 = false;
		}
		if(flag1 && flag2)
			return "both";
		else if(!flag1 && !flag2)
			return "none";
		else if(flag1)
			return "lexicographically";
		else
			return "lengths";
	}
};
/*
int main()
{
	TwoWaysSorting sol;
	vector<string> s;
	s.push_back("a");
	s.push_back("aa");
	s.push_back("bbb");
	cout << sol.sortingMethod(s) << endl;
	return 0;
}
*/
