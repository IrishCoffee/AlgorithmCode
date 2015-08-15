#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <iterator>
#include <unordered_set>
#include <queue>
using namespace std;

class Solution
{
	public:
		struct NODE
		{
			string word;
			int length;
		};
		int ladderLength(string start,string end,unordered_set<string> &dict)
		{
			if(start == end)
				return 1;
			unordered_set<string> exists;
			unordered_set<string>::iterator got;
			queue<NODE> q;
			NODE begin;
			begin.word = start;
			begin.length = 1;
			q.push(begin);
			exists.insert(start);
			int len = start.size();
			while(!q.empty())
			{
				NODE tmp = q.front();
				q.pop();
				for(int i = 0; i < len; ++i)
					for(int j = 0; j < 26; ++j)
					{
						string next = tmp.word;
						next[i] = 'a' + j;
						if(next == end)
							return tmp.length+1;
						if(next == tmp.word)
							continue;
						got = exists.find(next);
						if(got != exists.end())
							continue;
						got = dict.find(next);
						if(got != dict.end())
						{
							exists.insert(next);
							NODE temp;
							temp.word = next;
							temp.length = tmp.length+1;
							q.push(temp);
						}
					}
			}
			return 0;
		}
};

int main()
{
	string start = "hit";
	string end = "cog";
	unordered_set<string> dict;
	dict.insert("hot");
	dict.insert("dot");
	dict.insert("dog");
	dict.insert("lot");
	dict.insert("log");
	Solution sol;
	cout << sol.ladderLength(start,end,dict) << endl;
	return 0;
}


