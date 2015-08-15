#include <iostream>
#include <vector>
using namespace std;

class Solution
{
	public:
		vector<int> getRow(int rowIndex)
		{
			vector<int> v;
			v.push_back(1);
			rowIndex++;
			for(int i = 2; i <= rowIndex; ++i)
			{
				int tmp = v[0];
				for(int j = 1; j < i - 1; ++j)
				{
					int tmp1 = v[j];
					v[j] = tmp + v[j];
					tmp = tmp1;
				}
				v.push_back(1);
			}
			return v;

		}
};

int main()
{
	Solution sol;
	int n;
	cin >> n;
	vector<int>  v = sol.getRow(n);
	for(int i = 0; i < v.size(); ++i)
	{
		cout << v[i] << " ";
	}
	cout << endl;
	return 0;
}


