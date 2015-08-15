#include <iostream>
#include <cstdio>
using namespace std;

class Solution
{
	public:
		int firstMissingPositive(int A[],int n)
		{
			int small = -1;
			int big = -1;
			bool flag_0 = false;
			for(int i = 0; i < n; ++i)
			{
				if(A[i] <= 0)
					continue;
				if(small == -1 || small > A[i])
					small = A[i] - 1;
				else if(small == A[i])
					small--;
				if(small == 0)
					flag_0 = true;
				if(big == -1 || big < A[i])
					big = A[i] + 1;
				else if(big == A[i])
					big++;
			}
			if(flag_0)
				return big;
			else
				return small;
		}
};

int main()
{
	int A[32];
	int n;
	cin >> n;
	for(int i = 0; i < n; ++i)
		cin >> A[i];
	Solution sol;
	cout << sol.firstMissingPositive(A,n) << endl;
	return 0;
}

