#include <iostream>
#include <cstdio>
using namespace std;

class Solution
{
	public:
		int removeDuplicates(int A[],int n)
		{
			int cnt = 0;
			int p = 0;
			int cur = A[0];
			for(int i = 0; i < n; ++i)
			{
				if(A[i] == cur)
					cnt++;
				else
				{
					cnt = min(2,cnt);
					for(int j = 0; j < cnt; ++j)
						A[p++] = cur;
					cnt = 0;
					cur = A[i];
					i--;
				}
			}
			cnt = min(2,cnt);
			for(int j = 0; j < cnt; ++j)
				A[p++] = cur;
			return p;
		}
};

int main()
{
	int A[64];
	int n;
	cin >> n;
	for(int i = 0; i < n; ++i)
		cin >> A[i];
	Solution sol;
	n = sol.removeDuplicates(A,n);
	for(int i = 0; i < n; ++i)
		cout << A[i] << " ";
	cout << endl;
	return 0;
}



