#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;
class Solution
{
	public:
		void merge(int A[],int m,int B[],int n)
		{
			int p1 = m-1;
			int p2 = n-1;
			int p = m + n - 1;
			for(;p1 >= 0 && p2 >= 0; --p)
			{
				if(A[p1] >= B[p2])
				{
					A[p] = A[p1];
					p1--;
				}
				else
				{
					A[p] = B[p2];
					p2--;
				}
			}
			if(p1 >= 0)
			{
				for(;p1 >= 0;--p1)
					A[p--] = A[p1];
			}
			if(p2 >= 0)
			{
				for(;p2 >= 0; --p2)
					A[p--] = B[p2];
			}
		}
};

int main()
{
	int B[64] = {1,2,4,5,7};
	int A[64] = {8,9,10,11,12};
	Solution sol;
	int m = 5,n = 5;
	for(int i = 0; i < m; ++i)
		cout << A[i] << " ";
	cout <<endl;
	for(int i = 0; i < n; ++i)
		cout << B[i] << " ";
	cout << endl;

	sol.merge(A,m,B,n);
	for(int i = 0; i < m + n; ++i)
		cout << A[i] << " ";
	cout <<endl;
	return 0;
}


