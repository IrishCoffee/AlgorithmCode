//先从小的开始切，比如说15->3,5
//来5个人，那么切点就要是3,6,9,12
//如果是3个人，那么就要是3,5,6,9,10,12
//所以，对于每个约数，它的倍数都会是切点
//所以，切点的个数正好是n-n的欧拉函数（也就是不与n互质的点，都会成为切点）
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <stack>
#include <set>
using namespace std;

class MyVeryLongCake 
{
	public:
	int Euler(int n)
	{
		int i,ans = n;
		if(n % 2 == 0)
		{
			ans >>= 1;
			while(n % 2 == 0) n >>= 1;
		}
		for(i = 3; i * i  <= n; i += 2)
		{
			if(n % i == 0)
			{
				ans -= ans / i;
				while(n % i == 0) n /= i;
			}
		}
		if(n > 1) ans -= ans / n;
		return ans;
	}
	int cut(int n) 
	{
/*		set<int> ans;
		int len = sqrt(n);
		for(int i = 2; i <= len; ++i)
		{
			if(n % i != 0)
				continue;
			int another = n / i;
			for(int j = 1; i * j < n; ++j)
				ans.insert(i * j);
			for(int j = 1; another * j < n; ++j)
				ans.insert(another * j);
		}
		return ans.size() + 1;
*/		
		return n-Euler(n);		
	}
};
/*
int main()
{
	MyVeryLongCake sol;
	int n;
	cin >> n;
	cout << sol.cut(n) << endl;
	return 0;
}
*/
