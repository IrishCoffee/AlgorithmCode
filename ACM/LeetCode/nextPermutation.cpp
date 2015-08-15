#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;

class Solution
{
	public:
		void nextPermutation(vector<int> &num)
		{
			int size = num.size();
			if(size == 0)
				return;
			for(int i = size-1; i >= 1; --i)
			{
				if(num[i] > num[i-1])
				{
					int tmp = num[i];
					num[i] = num[i-1];
					num[i-1] = tmp;
					return;
				}
			}
			int tmp = num[0];
			num[0] = num[size-1];
			num[size-1] = tmp;
			return;
		}
};

int main()
{
	Solution sol;
	vector<int> v;
	int n;
	cin >> n;
	for(int i= 0; i < n; ++i)
	{
		int tmp;
		cin >> tmp;
		v.push_back(tmp);
	}
	sol.nextPermutation(v);
	for(int i = 0; i < v.size(); ++i)
		cout << v[i] << " ";
	cout << endl;
	return 0;
}

