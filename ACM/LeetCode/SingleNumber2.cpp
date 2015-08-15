#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

class Solution
{
	public:
		int singleNumber(int A[],int n)
		{
			int ones = 0,twos = 0,threes = 0;
			for(int i = 0; i < n; ++i)
			{
				threes = twos & A[i];
				twos = twos | (ones & A[i]);
				ones = ones | A[i];

				twos = twos & (~threes);
				ones = ones & (~threes);
	//			printf("%d one %d two %d three %d\n",A[i],ones,twos,threes);
			}
			return ones;
		}
};

int main()
{
	int A[10] = {1,2,3,4,1,2,3,1,2,3};
	Solution sol;
	cout << sol.singleNumber(A,10) << endl;
	return 0;
}
