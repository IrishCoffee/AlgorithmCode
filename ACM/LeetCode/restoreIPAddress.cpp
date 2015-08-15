#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
using namespace std;

class Solution
{
	public:
		vector<string> restoreIpAddresses(string s)
		{
			vector<string> v;
		//	if(s.size() > 9)
		//		return v;
			dfs(v,s,0,0);
			return v;
		}
		void dfs(vector<string> &v,string s,int index,int num)
		{
			if(num > 3) return;
			int size = s.size();
			char tmp[64];
			int id = 0;
			for(int i = index; i < size && i < index + 3; ++i)
			{
				tmp[id++] = s[i];
				tmp[id] = '\0';
				if(atoi(tmp) <= 255)
				{
					if(id > 1 && tmp[0] == '0')
						break;
					if(num == 3 && i == size - 1)
					{
						v.push_back(s);
						return;
					}
					string s1 = s;
					s1.insert(s1.begin() + i + 1,'.');
					dfs(v,s1,i+2,num+1);
				}
			}
		}
};

int main()
{
	Solution sol;
	string s;
	cin >> s;
	vector<string> v = sol.restoreIpAddresses(s);
	for(int i = 0; i < v.size(); ++i)
		cout << v[i] << endl;
	return 0;
}


