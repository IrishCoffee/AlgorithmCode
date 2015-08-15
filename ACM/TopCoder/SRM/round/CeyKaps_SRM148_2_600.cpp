#include <string>
#include <vector>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;

class CeyKaps 
{
	public:
	string decipher(string typed, vector <string> switches) 
	{
		int size = switches.size();
		
		int len = typed.size();
		for(int i = 0; i < len; ++i)
		{
			char cur = typed[i];
			for(int j = 0; j < size; ++j)
			{
				if(switches[j][0] == cur)
					cur = switches[j][2];
				else if(switches[j][2] == cur)
					cur = switches[j][0];
			}
			typed[i] = cur;
		}
		return typed;
	}
};

/*
int main()
{
	CeyKaps sol;
	string s1 = "A:B";
	string s2 = "B:C";
	string s3 = "C:D";
	string s4 = "D:E";
	string s5 = "E:A";
	vector <string> v;
	v.push_back(s1);
	v.push_back(s2);
	v.push_back(s3);
	v.push_back(s4);
	v.push_back(s5);
	string s = "ABCDE";
	cout << sol.decipher(s,v) << endl;
	

}
*/
