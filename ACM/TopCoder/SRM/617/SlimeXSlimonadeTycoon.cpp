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

class SlimeXSlimonadeTycoon 
{
	public:
	int sell(vector <int> morning, vector <int> customers, int stale_limit) 
	{
		int ans = 0;
		int sum = 0;
		int size = customers.size();
		for(int i = 0; i < size; ++i)
		{
			int tmp = 0;
			for(int j = i;j < i + stale_limit; ++j)
				tmp += customers[j];
			tmp = min(morning[i],tmp);
			sum += tmp;
			ans += min(sum,customers[i]);
			sum = max(0,sum - customers[i]);
		}
		return ans;
	}
};
/*
int main()
{
	SlimeXSlimonadeTycoon sol;
	int m[100] = {10,20,30};
	int c[100] = {30,20,10};
	int stale_limit = 1;
	vector<int> morning;
	vector<int> customers;
	for(int i = 0; i < 3; ++i)
	{
		morning.push_back(m[i]);
		customers.push_back(c[i]);
	}
	cout << sol.sell(morning,customers,stale_limit) << endl;
	return 0;
}

*/
