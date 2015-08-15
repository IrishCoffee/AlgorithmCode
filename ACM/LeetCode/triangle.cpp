#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

class Solution
{
	public:
		int minimumTotal(vector<vector<int> > &triangle)
		{
			for(int i = triangle.size() - 2; i >= 0; --i)
			{
				int len = triangle[i].size();
				for(int j = 0;j < len; ++j)
					triangle[i][j] += min(triangle[i+1][j],triangle[i+1][j+1]);
			}
			return triangle[0][0];
		}
};
int main()
{
	int num[4][4] = {{2},{3,4},{6,5,7},{4,1,8,3}};
	vector<vector<int> > v;
	vector<int> vv[4];
	for(int i = 0; i < 4;++i)
	{
		for(int j = 0; j <= i; ++j)
			vv[i].push_back(num[i][j]);
		v.push_back(vv[i]);
	}
	Solution sol;
	cout << sol.minimumTotal(v) << endl;
}
