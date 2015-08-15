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
using namespace std;

class SilverbachConjecture {
	public:
	bool isPrime[2048];
	void init()
	{
		memset(isPrime,true,sizeof(isPrime));
		isPrime[1] = false;
		for(int i = 2; i <= 2000; ++i)
		{
			if(isPrime[i])
			{
				for(int j = 2; i * j <= 2000; ++j)
					isPrime[i * j] = false;
			}
		}
		return;
	}
	vector <int> solve(int n) 
	{
		init();
		vector<int> ans;
		for(int i = 2; i <= n/2; ++i)
		{
			if(!isPrime[i] && !isPrime[n-i])
			{
				ans.push_back(i);
				ans.push_back(n-i);
				break;
			}
		}
		return ans;
	}
};
/*
int main()
{
	SilverbachConjecture sol;
	vector<int> ans;
	int n;
	cin >> n;
	ans = sol.solve(n);
	for(int i = 0; i < ans.size(); i+=2)
		cout << ans[i] << " " << ans[i+1] << endl;
	return 0;
}
*/
