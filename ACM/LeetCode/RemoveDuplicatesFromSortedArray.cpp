#include <iostream>
#include <cstdio>
using namespace std;

class Solution
{
	public:
		int removeDuplicates(int A[],int n)
		{
			int ans = n;
			int pointer = -1;
			bool first_same = false;
			bool has_duplicate = false;
			int current = A[0];
			for(int i = 1; i < n; ++i)
			{
			//	printf("%d %d\n",i,current);
				if(A[i] == current)
				{
					has_duplicate = true;
					ans--;
					if(pointer == -1)
						pointer = i;
				}
				else if(A[i] != current && has_duplicate)
				{
					//printf("Delete i %d current %d A[i] %d pointer %d\n",i,current,A[i],pointer);
					A[pointer] = A[i];
					pointer++;
					current = A[i];
				}
				else
					current = A[i];
			}
			return ans;
		}
};
int main()
{
	int A[12] = {1,1,1,1,1,1,1,1,1};
	int n = 9;
	for(int i = 0; i < n; ++i)
		cout << A[i] << " ";
	cout << endl;
	Solution sol;
	n = sol.removeDuplicates(A,n);
	for(int i = 0; i < n; ++i)
		cout << A[i] << " ";
	cout << endl;
	return 0;
}
