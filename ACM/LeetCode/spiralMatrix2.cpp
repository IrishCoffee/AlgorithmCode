#include <iostream>
#include <cstdio>
#include <vector>
#include <memory>
using namespace std;

class Solution
{
	public:
		vector<vector<int> > generateMatrix(int n)
		{
			vector<vector<int> > matrix;
			vector<int> v;
			v.resize(n);
			for(int i = 0; i < n; ++i)
				matrix.push_back(v);
			if(n == 0)
				return matrix;
			int i = 0;
			int size = n;
			int num = 1;
			while(size > 0)
			{

				dfs(matrix,i,num,size);
				i++;
				size -= 2;
			}
			return matrix;
		}
		void dfs(vector<vector<int> > & matrix,int n,int &num,int size)
		{
			for(int i = n; i < n + size;++i)
				matrix[n][i] = num++;
			for(int i = n + 1; i < n + size; ++i)
				matrix[i][n+size-1] = num++;
			for(int i = n + size - 2; i >= n; --i)
				matrix[n+size-1][i] = num++;
			for(int i = n + size - 2; i > n; --i)
				matrix[i][n] = num++;
			return;
		}
};

int main()
{
	vector<vector<int> > v;
	int n;
	cin >> n;
	Solution sol;
	v = sol.generateMatrix(n);
	for(int i = 0; i < v.size(); ++i)
	{
		for(int j = 0; j < v[i].size(); ++j)
			printf("%-3d ",v[i][j]);
		cout <<endl;
	}
	return 0;
}


