#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <iterator>
#include <unordered_set>
#include <queue>
using namespace std;

class Solution {
	public:
		int ladderLength(string start, string end, unordered_set<string> &dict) {
			int l = 1, i, j;
			dict.insert(end);
			unordered_set<string>::iterator it;
			it = dict.find(start);
			if(dict.find(end) == dict.end())
				return 0;
			if (it != dict.end()) dict.erase(it);
			queue<string> d;
			d.push(start);
			d.push("");
			int cnt = 0;
			int length = start.size();
			while(!d.empty())
			{
				string cur = d.front();
				d.pop();
				if (cur == "")
				{
					++l;
					if(!d.empty())
						d.push("");
					continue;
				}

				for (i = 0; i < length; ++i)
				{
					char t = cur[i];
					for (j = 0; j < 26; ++j)
					{
						cur[i] = 'a' + j;
						if (dict.find(cur) != dict.end())
						{
							if (cur == end) return l + 1;
							d.push(cur);
							dict.erase(cur);
						}
					}
					cur[i] = t;
				}
			}
			return 0;
		}
};

int main()
{
	string start = "hot";
	string end = "dog";
	unordered_set<string> dict;
	dict.insert("hot");
	dict.insert("dog");
	Solution sol;
	cout << sol.ladderLength(start,end,dict) << endl;
	return 0;
}


