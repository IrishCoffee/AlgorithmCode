#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>
using namespace std;

class Solution
{
	public:
		int majorityElement(vector<int> &num)
		{
			int size = num.size();
			int half_size = size / 2;
			priority_queue<int> q;
			for(int i = 0; i <= half_size; ++i)
				q.push(num[i]);
			for(int i = half_size + 1; i < size; ++i)
			{
				q.push(num[i]);
				q.pop();
			}
			return q.top();
		}
};

int main()
{
	Solution sol;
	int num[7] = {-1,100,2,100,100,4,100};
	vector<int> v;
	for(int i = 0; i < 7; ++i)
		v.push_back(num[i]);
	cout << sol.majorityElement(v) << endl;
	return 0;
}

			
