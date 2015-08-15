#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

class Solution
{
	public:
		int removeElement(int A[],int n,int elem)
		{
			int ans = n;
			int last = n-1;
			for(int i = 0; i <= last; ++i)
			{

				if(A[i] == elem)
				{
					ans--;
					swap(A[i],A[last]);
					last--;
					--i;
				}
			}
			return ans;
		}
		void swap(int &a,int &b)
		{
			int tmp = a;
			a = b;
			b = a;
			return;
		}
};
int main()
{
	Solution sol;
	//int A[16] = {0,1,0,1,1,1,1,2,3,4,5,6,7,1,0};
	int A[16] = {4,5};
	int n = 2;
	int ele = 4;
	for(int i= 0; i < n; ++i)
		cout << A[i] << " ";
	cout << endl;
	n = sol.removeElement(A,n,ele);
	for(int i = 0; i < n; ++i)
		cout << A[i] << " ";
	cout << endl;
	return 0;
}
