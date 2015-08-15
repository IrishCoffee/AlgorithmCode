#include <string>
#include <vector>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;

int num[14];
long long ans = -1;
class LuckySum 
{
	public:
		void test_add(int cur_pos,int alive,int carry,long long digit,long long sum,int add)
		{
			int new_carry = (carry + add) / 10;
			int cur_digit = (carry + add) % 10;
			if(num[cur_pos] == -1 || num[cur_pos] == cur_digit)
				dfs(cur_pos-1,alive,new_carry,digit * 10,cur_digit * digit + sum);
		}
		void dfs(int cur_pos,int alive,int carry,long long digit,long long sum)
		{
			//the end 
			if(cur_pos == -1)
			{
				if(carry == 0 && sum != 0 && (ans == -1 || ans > sum))
					ans = sum;
				return;
			}

			//at the beginning, for the last digit, it should be the sum of (4+4,4+7,7+7)
			if(alive == 2) 
			{
				alive = 1;
				test_add(cur_pos,alive,carry,digit,sum,8);
				test_add(cur_pos,alive,carry,digit,sum,11);
				test_add(cur_pos,alive,carry,digit,sum,14);
			}
			//after the beginning, for the middle digits, it can be sum of (4+4,4+7,7+7,4+0,7+0)
			else if(alive == 1)
			{
				test_add(cur_pos,alive,carry,digit,sum,8);
				test_add(cur_pos,alive,carry,digit,sum,11);
				test_add(cur_pos,alive,carry,digit,sum,14);
				alive = 0;
				test_add(cur_pos,alive,carry,digit,sum,4);
				test_add(cur_pos,alive,carry,digit,sum,7);
			}
			//once the alive is 0, we can only add 4 or 7 since one of the lucky nummber cannot offer digit any more 
			//e.g. 444 + 4,444 + 74
			else
			{
				test_add(cur_pos,alive,carry,digit,sum,4);
				test_add(cur_pos,alive,carry,digit,sum,7);
			}
			if(cur_pos == 0 && carry != 0)
				test_add(cur_pos,alive,carry,digit,sum,0);
		}
		long long construct(string note) 
		{
			int size = note.size();
			memset(num,-1,sizeof(num));
			for(int i = 0; i < size; ++i)
				if(note[i] != '?')
					num[i] = note[i] - '0';
			dfs(size - 1,2,0,1,0);
			return ans;
		}
};
/*
int main()
{
	LuckySum sol;
	string s;
	cin >> s;
	cout << sol.construct(s) << endl;
}
*/
