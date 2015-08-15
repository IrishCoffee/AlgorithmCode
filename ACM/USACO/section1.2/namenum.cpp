/*
ID: irishco1
PROG: namenum
LANG: C++
*/
#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;
int code[26] = {2,2,2,3,3,3,4,4,4,5,5,5,6,6,6,7,1,7,7,8,8,8,9,9,9,1};
struct NODE
{
	char word[16];
	long long int id;
}dict[5000];
int main()
{
	FILE *fp = fopen("dict.txt","r");
	int cnt = 0;
	while(fscanf(fp,"%s",dict[cnt].word) == 1)
	{
		int len = strlen(dict[cnt].word);
		dict[cnt].id = 0;
		for(int i = 0; i < len; ++i)
			dict[cnt].id = dict[cnt].id * 10 + code[(dict[cnt].word[i] - 'A')];
		cnt++;
	}
//	cout << dict[2348].word << " " << dict[2348].id << endl;
	fclose(fp);
	freopen("namenum.in","r",stdin);
	freopen("namenum.out","w",stdout);
	long long int number;
	scanf("%lld",&number);
	bool flag = true;
	for(int i = 0; i < cnt;++i)
	{
		if(dict[i].id == number)
		{
			flag = false;
			printf("%s\n",dict[i].word);
		}
	}
	if(flag)
		printf("NONE\n");
	return 0;
}




