#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;

struct Interval
{
	int start;
	int end;
	Interval(): start(0),end(0) {}
	Interval(int s,int e): start(s),end(e){}
};

bool operator<(Interval a,Interval b)
{
	return a.start < b.start;
}
class Solution
{
	public:
		vector<Interval> merge(vector<Interval> &intervals)
		{
			vector<Interval> v;
			sort(intervals.begin(),intervals.end());
			int s = -1;
			int e = -1;
			int size = intervals.size();
			if(size == 0)
				return v;
			for(int i = 0; i < size; ++i)
			{
				if(s == -1 && e == -1)
				{
					s = intervals[i].start;
					e = intervals[i].end;
				}
				else if(intervals[i].start >=  s && intervals[i].start <= e)
					e = max(e,intervals[i].end);
				else if(intervals[i].start > e)
				{
					Interval tmp(s,e);
					s = intervals[i].start;
					e = intervals[i].end;
					v.push_back(tmp);
				}
			}
			Interval tmp(s,e);
			v.push_back(tmp);
			return v;
		}
};

int main()
{
	int s[10] = {1,2,6,15};
	int e[10] = {4,3,10,18};
	vector<Interval> v;
	for(int i = 0; i < 2; ++i)
	{
		Interval tmp(s[i],e[i]);
		v.push_back(tmp);
	}
	Solution sol;
	v = sol.merge(v);
	int size = v.size();
	for(int i = 0; i < size; ++i)
		cout << v[i].start << " " << v[i].end << endl;
	return 0;
}


