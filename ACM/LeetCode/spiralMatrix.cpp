#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

class Solution
{
	public:
		vector<int> spiralOrder(vector<vector<int> > &matrix)
		{
			vector<int> v;
			int r = matrix.size();
			if(r == 0)
				return v;
			int c = matrix[0].size();
			if(c == 0)
				return v;
			int n = 0;
			while(r * c > 0)
			{

				dfs(matrix,v,n,r,c);
				n++;
				r -= 2;
				c -= 2;
			}
			return v;
		}
		void dfs(vector<vector<int> > & matrix,vector<int> &v,int n,int r,int c)
		{
			for(int i = n; i < n + c;++i)
				v.push_back(matrix[n][i]);
			if(r == 1)
				return;
			for(int i = n + 1; i < n + r; ++i)
				v.push_back(matrix[i][n+c-1]);
			if(c == 1)
				return;
			for(int i = n + c - 2; i >= n; --i)
				v.push_back(matrix[n+r-1][i]);
			for(int i = n + r - 2; i > n; --i)
				v.push_back(matrix[i][n]);
			return;
		}
};

int main()
{
	vector<vector<int> > v;
	int m,n;
	cin >> m >> n;
	int tmp = 1;
	for(int i = 0; i < m; ++i)
	{
		vector<int> m;
		for(int j = 0; j < n; ++j)
			m.push_back(tmp++);
		v.push_back(m);
	}
	for(int i = 0; i < m; ++i)
	{
		for(int j = 0; j < n; ++j)
			cout << v[i][j] << " ";
		cout << endl;
	}
	cout << endl;
	Solution sol;
	vector<int> mm = sol.spiralOrder(v);
	for(int i = 0; i < mm.size(); ++i)
		cout << mm[i] << " ";
	cout <<endl;
	return 0;
}


