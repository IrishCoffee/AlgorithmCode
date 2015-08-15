#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <iterator>
#include <unordered_set>
#include <queue>
#include <vector>
using namespace std;

class Solution
{
	public:
		struct NODE
		{
			string word;
			vector<string> ans;
			int length;
		};
		vector<vector<string> > findLadders(string start,string end,unordered_set<string> &dict)
		{
			vector<vector<string> > final_ans;
			if(start == end)
			{
				vector<string> v;
				v.push_back(start);
				v.push_back(start);
				final_ans.push_back(v);
				return final_ans;
			}
			unordered_set<string> exists;
			unordered_set<string>::iterator got;
			queue<NODE> q;

			NODE begin;
			begin.word = start;
			begin.length = 1;
			begin.ans.push_back(start);

			q.push(begin);
			int len = start.size();
			int min = -1;
			while(!q.empty())
			{
				NODE tmp = q.front();
				q.pop();
				while(true)
				{
					got = dict.find(tmp.word);
					if(got == dict.end())
						break;
					dict.erase(tmp.word);
				}
				exists.insert(tmp.word);
				for(int i = 0; i < len; ++i)
					for(int j = 0; j < 26; ++j)
					{
						string next = tmp.word;
						next[i] = 'a' + j;
						if(next == end)
						{
							if(min == -1 || tmp.length + 1 == min)
							{
								min = tmp.length+1;
								tmp.ans.push_back(end);
								final_ans.push_back(tmp.ans);
								goto Lable1;
							}
							else
								goto Lable2;
						}
						if(next == tmp.word)
							continue;
						got = exists.find(next);
						if(got != exists.end())
							continue;
						got = dict.find(next);
						if(got != dict.end())
						{
							NODE temp;
							temp.word = next;
							temp.ans = tmp.ans;
							temp.ans.push_back(next);
							temp.length = tmp.length+1;
							q.push(temp);
						}
					}
Lable1:			continue;
			}

Lable2:		return final_ans;
		}
};
int main()
{
	string start = "red";
	string end = "tax";
	unordered_set<string> dict;
	dict.insert("ted");
	dict.insert("tex");
	dict.insert("red");
	dict.insert("tax");
	dict.insert("tad");
	dict.insert("den");
	dict.insert("rex");
	dict.insert("pee");
	Solution sol;
	vector<vector<string> > ans = sol.findLadders(end,start,dict);
	for(int i = 0; i < ans.size(); ++i)
	{
		for(int j = 0; j < ans[i].size(); ++j)
			cout << ans[i][j] << " " ;
		cout << endl;
	}

	return 0;
}


