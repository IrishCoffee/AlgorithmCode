#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;

class Solution
{
	public:
		void rotate(vector<vector<int> > &matrix)
		{
			int n = matrix.size();
			for(int i = 0;; ++i)
			{
				f(matrix,n - 1,i,i);
				n -= 2;
				if(n <= 1)
					break;
			}
			return;
		}
		void f(vector<vector<int> > &matrix,int size,int r,int c)
		{
			int n = matrix.size() - 1;
			for(int k = 0; k < size; ++k)
			{
				int i = r + k;
				int j = c;
				int tmp = matrix[j][n-i];
				matrix[j][n-i] = matrix[i][j];

				int tmp1 = matrix[n-i][n-j];
				matrix[n-i][n-j] = tmp;

				tmp = matrix[n-j][i];
				matrix[n-j][i] = tmp1;

				matrix[i][j] = tmp;
			}
		/*	for(int i = 0; i <= n; ++i)
			{
				for(int j = 0; j <= n; ++j)
					printf("%-3d",matrix[i][j]);
				cout << endl;
			}
			cout << endl;
		*/
		}
};

int main()
{
	vector<vector<int> >  matrix;
	int n;
	cin >> n;
	int num = 1;
	for(int i = 0; i < n; ++i)
	{
		vector<int> v;
		for(int j = 0; j < n; ++j)
			v.push_back(num++);
		matrix.push_back(v);
	}
	for(int i = 0; i < n; ++i)
	{
		for(int j = 0; j < n; ++j)
			printf("%-3d",matrix[i][j]);
		cout << endl;
	}
	cout << endl;
	Solution sol;
	sol.rotate(matrix);
	for(int i = 0; i < n; ++i)
	{
		for(int j = 0; j < n; ++j)
			printf("%-3d",matrix[i][j]);
		cout << endl;
	}
	return 0;
}


