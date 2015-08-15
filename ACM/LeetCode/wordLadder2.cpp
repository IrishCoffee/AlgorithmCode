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
		vector<vector<string> > findLadders(string start,string end,unordered_set<string> &dict)
		{
			vector<
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


