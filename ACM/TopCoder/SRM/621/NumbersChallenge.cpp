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
using namespace std;

class NumbersChallenge 
{
	public:
		vector<int> v;
		int size;
		void f(int &tmp,int len,vector<int> &S)
		{
			if(len == size)
			{
				v.push_back(tmp);
				return;
			}
			tmp += S[len];
			f(tmp,len+1,S);
			tmp -= S[len];
			f(tmp,len+1,S);
			return;
		}
		int MinNumber(vector <int> S) 
		{
			size = S.size();
			int tmp = 0;
			f(tmp,0,S);
			size = v.size();
			sort(v.begin(),v.end());
			for(int i = 1; i < size; ++i)
			{
			//	cout << v[i] <<endl;
				if((v[i] - v[i-1]) > 1)
					return v[i-1] + 1;
			}
			return v[size-1] + 1;
		}
};
/*
   int main()
   {
   NumbersChallenge sol;
   vector<int> S;
   S.push_back(1);
   S.push_back(2);
   S.push_back(4);
   cout << sol.MinNumber(S) << endl;
   return 0;
   }
 */ 
