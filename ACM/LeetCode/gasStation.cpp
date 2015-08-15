#include <iostream>
#include <vector>
using namespace std;

class Solution
{
	public:
		int canCompleteCircuit(vector<int> &gas,vector<int> &cost)
		{
			vector<int> A;
			int size = gas.size();
			for(int i = 0; i < size; ++i)
				A.push_back(gas[i] - cost[i]);
			for(int i = 0; i < size; ++i)
			{
				int tmp = 0;
				if(A[i] >= 0)
				{
					int s = i;
					int j = 0;
					for(;j < size; ++j)
					{
						if(tmp + A[s] >= 0)
						{
							tmp += A[s++];
							if(s >= size)
								s = 0;
						}
						else
							break;
					}
					if(j == size)
						return i;
				}
			}
			return -1;
		}
};

int main()
{
	vector<int> v1;
	vector<int> v2;
	int g[10] = {3,1,2,4};
	int c[10] = {4,2,1,3};
	for(int i = 0; i < 4; ++i)
	{
		v1.push_back(g[i]);
		v2.push_back(c[i]);
	}
	Solution sol;
	cout << sol.canCompleteCircuit(v1,v2) << endl;
	return 0;
}


						

