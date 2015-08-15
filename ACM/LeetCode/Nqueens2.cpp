#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <cmath>
using namespace std;

class Solution
{
	public:
		int totalNQueens(int n)
		{
			if(n == 0)
				return 0;
			int pos[n];
			int ans = 0;
			solve(ans,pos,n,0);
			return ans;
		}
		bool check(int pos[],int row)
		{
			for(int i = 0; i < row; ++i)
					if(pos[i] == pos[row] || fabs(pos[i] - pos[row]) == fabs(i - row))
						return false;
			return true;
		}
		void solve(int  &ans,int pos[],int n,int row)
		{
			if(row == n)
			{
				ans++;
				return;
			}
			for(int i = 0; i < n; ++i)
			{
				pos[row] = i;
				if(check(pos,row))
					solve(ans,pos,n,row+1);
			}
			return;
		}
};
int main()
{
	int n;
	cin >> n;
	Solution sol;
	cout << sol.totalNQueens(n) << endl;
	return 0;
}
