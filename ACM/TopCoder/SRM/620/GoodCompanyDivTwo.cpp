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

class GoodCompanyDivTwo 
{
	public:
	int countGood(vector <int> superior, vector <int> workType) 
	{
		bool flag[128];
		int ans = 0;
		int len = superior.size();
		for(int i = 0; i < len; ++i)
		{
			bool ff = true;
			memset(flag,true,sizeof(flag));
			flag[workType[i]] = false;
			for(int j = 1; j < len; ++j)
			{
				if(j != i && superior[j] == i)
				{
					if(flag[workType[j]])
						flag[workType[j]] = false;
					else
					{
						ff = false;
						break;
					}
				}
			}
			if(ff)
				ans++;
		}
		return ans;
	}
};
/*
int main()
{
	GoodCompanyDivTwo sol;
	vector<int> v;
	vector<int> w;
	v.push_back(-1);
	v.push_back(0);
	w.push_back(1);
	w.push_back(1);
	cout << sol.countGood(v,w) << endl;
	return 0;
}
*/
