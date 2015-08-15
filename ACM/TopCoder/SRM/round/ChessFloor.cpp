#include <string>
#include <vector>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <cstdio>
using namespace std;

class ChessFloor {
	public:
	int check(vector<string> floor,char colorA, char colorB)
	{
		int N = floor.size();
		int cnt = 0;
		for(int i = 0; i < N; ++i)
		{
			for(int j = 0; j < N; j += 2)
			{
				if(floor[i][j] != colorA)
					cnt++;
				if(j < N-1)
				{
					if(floor[i][j+1] != colorB)
						cnt++;
				}
			}
			char tmp = colorA;
			colorA = colorB;
			colorB = tmp;
		}
		return cnt;

	}


	int minimumChanges(vector <string> floor) 
	{
		int usedColor[26];
		memset(usedColor,0,sizeof(int) * 26);
		int N = floor.size();
		int colorCnt = 0;
		for(int i = 0; i < N; ++i)
			for(int j = 0; j < N; ++j)
				usedColor[floor[i][j] - 'a'] = 1;
		for(int i = 0; i <26; ++i)
			if(usedColor[i])
				colorCnt++;
		if(colorCnt == 1)
			return N * N / 2;
		char colorA, colorB;
		int ans = -1;
		for(int i = 0; i < 26; ++i)
		{
			if(!usedColor[i])
				continue;
			colorA = 'a' + i;
			for(int j = i + 1; j < 26; ++j)
			{
				if(!usedColor[j])
					continue;
				colorB = 'a' + j;
				if(ans == -1)
					ans = check(floor,colorA,colorB);
				else
					ans = min(ans,check(floor,colorA,colorB));
				ans = min(ans,check(floor,colorB,colorA));
			}
		}
		return ans;
	}
};
/*
int main()
{
	ChessFloor sol;
	vector<string> v;
	v.push_back("aba");
	v.push_back("bbb");
	v.push_back("aba");
	cout << sol.minimumChanges(v) << endl;
}
*/
