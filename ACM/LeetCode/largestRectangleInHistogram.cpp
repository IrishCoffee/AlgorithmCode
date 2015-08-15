#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class Solution
{
	public:
		int largestRectangleArea(vector<int> &height)
		{
			int size = height.size();
			if(size == 0)
				return 0;
			int width = 1,h = height[0];
			int ans = h;
			for(int i = 1; i < size; ++i)
			{
				int area = min(height[i],h) * (width + 1);
				if(height[i] >= area)
				{
					ans = max(height[i],ans);
					h = height[i];
					width = 1;
				}
				else
				{
					ans = max(ans,area);
					h = min(height[i],h);
					width++;
				}
			}
			return ans;
		}
};

int main()
{
	int h[6] = {1,2,3,4,5};
	vector<int> v;
	for(int i = 0; i < 5; ++i)
		v.push_back(h[i]);
	Solution sol;
	cout << sol.largestRectangleArea(v) << endl;
	return 0;
}
				
