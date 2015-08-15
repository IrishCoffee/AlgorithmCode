#include <string>
#include <vector>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;

class LuckyXor {
	public:
	bool check(int a,int b)
	{
		int ans = a ^ b;
		while(ans)
		{
			if(ans % 10 == 4 || ans % 10 == 7)
				ans /= 10;
			else
				return false;
		}
		return true;
	}
	int construct(int a) 
	{
		for(int i = a + 1; i <= 100; ++i)
		{
			if(check(i,a))
				return i;
		}
		return -1;
	}
};

