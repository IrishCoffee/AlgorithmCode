#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
using namespace std;

class Solution
{
	public:
		int compareVersion(string version1, string version2)
		{
			int i = 0, j = 0;
			int size1 = version1.size();
			int size2 = version2.size();
			while(i < size1 && j < size2)
			{
				int n1 = 0,n2 = 0;
				for(;i < size1; ++i)
				{
					if(version1[i] == '.')
						break;
					n1 *= 10;
					n1 += version1[i] - '0';
				}
				for(;j < size2; ++j)
				{
					if(version2[j] == '.')
						break;
					n2 *= 10;
					n2 += version2[j] - '0';
				}
				if(n1 < n2)
					return -1;
				else if(n1 > n2)
					return 1;
				i++,j++;
			}
			if(i < size1)
			{
				int n1 = 0;
				for(; i < size1; ++i)
				{
					if(version1[i] == '.')
						break;
					n1 *= 10;
					n1 += version1[i] - '0';
				}
				if(n1 != 0)
					return 1;
				else
					return 0;
			}
			else if(j < size2)
			{
				int n2 = 0;
				for(; j < size2; ++j)
				{
					if(version2[j] == '.')
						break;
					n2 *= 10;
					n2 += version2[j] - '0';
				}
				if(n2 != 0)
					return -1;
				else
					return 0;
			}
			else
				return 0;
		}
};

int main()
{
	Solution sol;
	string v1,v2;
	cin >> v1 >> v2;
	cout << sol.compareVersion(v1,v2) << endl;
}
