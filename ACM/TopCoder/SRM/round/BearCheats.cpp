#include <string>
#include <vector>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <cstdio>
using namespace std;

class BearCheats {
	public:
	string eyesight(int A, int B) 
	{
		string happy = "happy";
		string glass = "glasses";
		bool success = true;
		int cnt = 0;
		while(A && B)
		{
			int a = A % 10;
			int b = B % 10;
			A /= 10;
			B /= 10;
			if(a != b)
				cnt++;
		}
		if(A == 0 && B == 0 && cnt <= 1)
			return happy;
		else
			return glass;
	}
};
/*
int main()
{
	BearCheats sol;
	cout << sol.eyesight(8072,3072) << endl;
	return 0;
}
*/
