#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

class Solution
{
	public:
		int searchInsert(int A[],int n,int target)
		{
			if(A[0] > target) return 0;
			if(A[n-1] < target) return n;
			if(A[n-1] == target) return n-1;
			for(int i = 0; i < n-1; ++i)
			{
				if(A[i] == target)
					return i;
				if(A[i] < target && A[i+1] > target)
					return i+1;
			}
		}
};

int main()
{
	int target;
	int A[64];
	int n;
	cin >> n;
	for(int i = 0; i < n; ++i)
		cin >> A[i];
	cin >> target;
	Solution sol;
	cout << sol.searchInsert(A,n,target) << endl;
	return 0;
}
