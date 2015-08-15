#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
using namespace std;

class Solution
{
	public:
		void sortColors(int A[],int n)
		{
			int red = 0,white = 0,blue = n-1;
			while(white <= blue)
			{
				if(A[white] == 0)
				{
					swap(A[white],A[red]);
					red++;
					white++;
				}
				else if(A[white] == 2)
				{
					swap(A[white],A[blue]);
					blue--;
				}
				else
				{
					while(A[white] == 1)
						white++;
				}
			}
			return;
		}
		void swap(int &a,int &b)
		{
			int tmp = a;
			a = b;
			b = tmp;
		}
};
int main()
{
	int A[12] = {1,2,0};
	int n = 3;
	Solution sol;
	sol.sortColors(A,n);
	for(int i = 0; i < n; ++i)
		cout << A[i] << " ";
	cout << endl;
}



				
