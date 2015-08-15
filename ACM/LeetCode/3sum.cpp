#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
using namespace std;
class Solution
{
	public:
		vector<vector<int> > threeSum(vector<int> &num)
		{
			vector<vector<int> > ans;
			if(num.size() == 0)
				return ans;
			int len = num.size(),e = len -1;
			sort(num.begin(),num.end());
			for(int i = 0; i < len - 2; ++i)
			{
				if(num[i] > 0)
					break;
				while(i > 0 && num[i] == num[i-1])
					++i;
				int target = (-1) * num[i];
				int end = len - 1;
				for(int j = i + 1; j < len; ++j)
				{
					for(int k = end; k > j; --k)
					{
						if(num[j] + num[k] > target)
							continue;
						else if(num[j] + num[k] < target)
						{
							end = k;
							break;
						}
						else
						{
							vector<int> v;
							v.push_back(num[i]);
							v.push_back(num[j]);
							v.push_back(num[k]);
							ans.push_back(v);
							break;
						}
					}
					while(num[j] == num[j + 1])
						++j;
				}
			}
			return ans;
		}
};

int main()
{
	int num[36] = {
		-3,-3,-3,6
	};
	vector<int> v;
	for(int i = 0;i < 4; ++i)
		v.push_back(num[i]);
	vector<vector<int> > ans;
	Solution sol;
	ans = sol.threeSum(v);
	for(int i = 0; i < ans.size(); ++i)
	{
		for(int j = 0; j < 3; ++j)
			cout << ans[i][j] << " ";
		cout << endl;
	}
	return 0;
}
