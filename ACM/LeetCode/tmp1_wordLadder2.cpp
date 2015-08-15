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
			int length;
			NODE * prev;
		};
		vector<vector<string> > findLadders(string start,string end,unordered_set<string> &dict)
		{
			vector<vector<string> > final_ans;
			unordered_set<string> exists;
			unordered_set<string>::iterator got;
			vector<NODE *> ans;
			queue<NODE *> q;
			
			string tmp = start;
			start = end;
			end = tmp;

			NODE begin;
			begin.prev = NULL;
			begin.word = start;
			begin.length = 1;

			q.push(&begin);
			int len = start.size();
			int min = -1;
			while(!q.empty())
			{
				NODE *tmp = new NODE;
				tmp = q.front();
				q.pop();
				dict.erase(tmp->word);
				exists.insert(tmp->word);
				for(int i = 0; i < len; ++i)
					for(int j = 0; j < 26; ++j)
					{
						string next = tmp->word;
						next[i] = 'a' + j;
						if(next[i] == tmp->word[i])
							continue;
						if(next == end)
						{
							if(min == -1 || tmp->length + 1 == min)
							{
								min = tmp->length+1;
								NODE *nn = new NODE;
								nn->word = end;
								nn->prev = tmp;
								ans.push_back(nn);
								goto Lable1;
							}
							else
								goto Lable2;
						}
						got = exists.find(next);
						if(got != exists.end())
							continue;
						got = dict.find(next);
						if(got != dict.end())
						{
							NODE *temp = new NODE;
							temp->word = next;
							temp->prev = tmp;
							temp->length = tmp->length+1;
							q.push(temp);
						}
					}
Lable1:			continue;
			}
Lable2:		int size = ans.size();
			for(int i = 0; i < size; ++i)
			{
				vector<string> v;
				NODE *tmp = ans[i];
				while(tmp != NULL)
				{
					v.push_back(tmp->word);
					tmp = tmp->prev;
				}
				final_ans.push_back(v);
			}
			return final_ans;
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
	vector<vector<string> > ans = sol.findLadders(start,end,dict);
	for(int i = 0; i < ans.size(); ++i)
	{
		for(int j = 0; j < ans[i].size(); ++j)
			cout << ans[i][j] << " " ;
		cout << endl;
	}

	return 0;
}


