#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

class Solution
{
	public:
		vector<int> searchRange(int A[],int n,int target)
		{
			vector<int> v;
			v.push_back(-1);
			v.push_back(-1);

			if(A[n-1] < target || A[0] > target)
				return v;

			int left = 0,right = n-1;
			
			while(left <= right)
			{
				int mid = (left + right) / 2;
				if(A[mid] == target) // find the start point
				{
					if(mid == 0 || A[mid-1] < target)
					{
						v[0] = mid;
						break;
					}
					else
						right = mid-1;
				}
				else if(A[mid] < target)
					left = mid + 1;
				else
					right = mid - 1;
			}
			if(v[0] == -1) return v;

			left = v[0];
			right = n-1;

			while(left <= right)
			{
				int mid = (left + right) / 2;
				if(A[mid] == target)
				{
					if(mid == n-1 || A[mid+1] > target)
					{
						v[1] = mid;
						return v;
					}
					else
						left = mid + 1;
				}
				else if(A[mid] > target)
					right = mid -1;
				else
					left = mid + 1;
			}
			return v;
		}
};

int main()
{
	Solution sol;
	int A[64] = {6,6,6,8,8,8};
	int target = 7;
	int n = 6;
	vector<int> v = sol.searchRange(A,n,target);
	cout << v[0] << " " << v[1] << endl;
}

