#include <iostream>
#include <vector>
using namespace std;

class Solution
{
	public:
		vector<vector<int> > generate(int numRows)
		{
			vector<vector<int> > v;
			if(numRows == 0) return v;
			vector<int> vv;
			vv.push_back(1);
			v.push_back(vv);
			for(int i = 1; i < numRows; ++i)
			{
				vector<int> m;
				m.push_back(1);
				for(int j = 1; j <= i-1; ++j)
					m.push_back(v[i-1][j-1] + v[i-1][j]);
				m.push_back(1);
				v.push_back(m);
			}
			return v;
		}
};

int main()
{
	Solution sol;
	int n;
	cin >> n;
	vector<vector<int> > v = sol.generate(n);
	for(int i = 0; i < v.size(); ++i)
	{
		for(int j = 0; j < v[i].size(); ++j)
			cout << v[i][j] << " ";
		cout << endl;
	}
	return 0;
}


