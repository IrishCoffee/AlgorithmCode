// BEGIN CUT HERE

// END CUT HERE
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
#include <unordered_set>
using namespace std;

class MovingRooksDiv2 
{
	public:
	string move(vector <int> Y1, vector <int> Y2) 
	{
		string yes = "Possible";
		string no = "Impossible";
		queue<string> q;
		unordered_set<string> flag;
		int len = Y1.size();
		string tmp,goal;
		
		for(int i = 0; i < len; ++i)
		{
			tmp += Y1[i] + '0';
			goal += Y2[i] + '0';
		}
		if(tmp.compare(goal) == 0)
			return yes;
		q.push(tmp);
		while(!q.empty())
		{
			tmp = q.front();
			q.pop();
			flag.insert(tmp);
			for(int i = 0; i < len; ++i)
			{
				for(int j = i+1; j < len; ++j)
				{
					if(tmp[i] - '0' > tmp[j] - '0')
					{
						string next = tmp;
						next[j] = tmp[i];
						next[i] = tmp[j];
						if(next.compare(goal) == 0)
							return yes;
						if(flag.find(next) == flag.end()) // no 
							q.push(next);
					}
				}
			}
		}
		return no;
	}
};

/*
int main()
{
	MovingRooksDiv2 sol;
	vector<int> y1,y2;
	int n;
	cin >> n;
	int num;
	for(int i = 0; i < n; ++i)
	{
		cin >> num;
		y1.push_back(num);
	}
	for(int i = 0; i < n; ++i)
	{
		cin >> num;
		y2.push_back(num);
	}
	cout << sol.move(y1,y2) << endl;
	return 0;
}
*/
