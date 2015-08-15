#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
	public:
		vector<vector<int> >fourSum(vector<int> &num,int target)
		{
			vector<vector<int> > ans;
			int len = num.size();
			sort(num.begin(),num.end());
			for(int i = 0; i < len; ++i)
			{
				int a = num[i];
				if(i > 0 && num[i] == num[i-1])
					continue;
				for(int j = i + 1; j < len; ++j)
				{
					if(j > i+1 && num[j] == num[j-1])
						continue;
					int b = num[j];
					int r = len - 1;
					int sum = target - a - b;
					for(int l = j + 1;l < r;++l)
					{
						if(l > j+1 && num[l] == num[l-1])
							continue;
						int c = num[l];
						for(r = len - 1;r > l; --r)
						{
							int d = num[r];
							if(c + d > sum)
								continue;
							if(c + d == sum)
							{
								vector<int> v;
								v.push_back(a);
								v.push_back(b);
								v.push_back(c);
								v.push_back(d);
								ans.push_back(v);
								while(num[r-1] == d)
									--r;
							}
							if(c + d < sum)
								break;
						}
					}
				}
			}
			return ans;
		}
};

int main()
{
	Solution sol;
	vector<int> v;
//	int num[100] = {5,5,3,5,1,-5,1,2};
	int num[100] = {-3,-2,-1,0,0,1,2,3};
	for(int i = 0; i < 8; ++i)
		v.push_back(num[i]);
	vector<vector<int> > ans;
	ans = sol.fourSum(v,0);
	for(int i = 0; i < ans.size(); ++i)
	{
		for(int j = 0;j < 4; ++j)
			cout << ans[i][j] << " ";
		cout << endl;
	}
	return 0;
}




