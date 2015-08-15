#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <cstdio>
using namespace std;

class Solution
{
	public:
		int maxArea(vector<int> &height)
		{
			int right = height.size() - 1,left = 0;
			int size = height.size();
			int ans = 0;
			bool changed = true;
			while(left < right && changed)
			{
				changed = false;
				int temp = min(height[left],height[right]) * (right - left);
				if(temp > ans)
					ans = temp;
				if(height[left] <= height[right])
					for(int i = left; i < size; ++i)
					{
						if(height[i] > height[left])
						{
							left = i;
							changed = true;
							break;
						}
					}
				else
					for(int i = right; i >= 0; --i)
					{
						if(height[i] > height[right])
						{
							right = i;
							changed = true;
							break;
						}
					}
			}
			return ans;
		}
};

int main()
{
	Solution sol;
	vector<int> h;
	int n;
	cin >> n;
	while(n--)
	{
		int tmp;
		cin >> tmp;
		h.push_back(tmp);
	}
	cout << sol.maxArea(h) << endl;
}
