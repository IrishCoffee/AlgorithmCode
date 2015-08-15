#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
using namespace std;

class Solution
{
	public:
		bool searchMatrix(vector<vector<int> > &matrix,int target)
		{
			int m = matrix.size();
			if(m == 0)
				return false;
			int n = matrix[0].size();
			if(n == 0)
				return false;
			int left = 0,right = m * n - 1;
			while(left <= right)
			{
				int mid = (left + right) / 2;
				int i = mid / n;
				int j = mid % n;
				if(matrix[i][j] < target)
					left = mid + 1;
				else if(matrix[i][j] > target)
					right = mid - 1;
				else
					return true;
			}
			return false;
		}
};

int main()
{
	vector<vector<int> > v;
	int num[5][5] = {{1,3,5,7},{10,11,16,20},{23,30,34,50}};
	for(int i = 0; i < 3; ++i)
	{
		vector<int> tmp;
		for(int j = 0; j < 4; ++j)
			tmp.push_back(num[i][j]);
		v.push_back(tmp);
	}	
	Solution sol;
	int target;
	cin >> target;
	cout << sol.searchMatrix(v,target) << endl;
	return 0;
}
