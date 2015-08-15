/*
ID: irishco1
PROG: transform
LANG: C++
*/
#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;
char input[16][16];
char tmp[8][16][16];
char output[16][16];
bool judge(int n,char in[16][16],char out[16][16])
{
	for(int i = 0; i < n; ++i)
		for(int j = 0;j < n; ++j)
			if(in[i][j] != out[i][j])
				return false;
	return true;
}
void rotation(int n,char in[16][16],char out[16][16])
{
	for(int i = 0; i < n;++i)
		for(int j = 0; j < n; ++j)
			in[i][j] = out[n-1-j][i];
	return;
}
void reflection(int n,char in[16][16],char out[16][16])
{
	for(int i = 0; i < n; ++i)
		for(int j = 0; j < n; ++j)
			in[i][j] = out[i][n-1-j];
	return;
}
int main()
{
	freopen("transform.in","r",stdin);
	freopen("transform.out","w",stdout);
	int N;
	scanf("%d",&N);
	for(int i = 0; i < N; ++i)
		scanf("%s",input[i]);
	for(int i = 0; i < N; ++i)
		scanf("%s",output[i]);
	
	rotation(N,tmp[1],input);
	if(judge(N,tmp[1],output))
	{
		printf("1\n");
		return 0;
	}

	rotation(N,tmp[2],tmp[1]);
	if(judge(N,tmp[2],output))
	{
		printf("2\n");
		return 0;
	}

	rotation(N,tmp[3],tmp[2]);
	if(judge(N,tmp[3],output))
	{
		printf("3\n");
		return 0;
	}

	reflection(N,tmp[4],input);
	if(judge(N,tmp[4],output))
	{
		printf("4\n");
		return 0;
	}

	rotation(N,tmp[5],tmp[4]);
	if(judge(N,tmp[5],output))
	{
		printf("5\n");
		return 0;
	}

	rotation(N,tmp[6],tmp[5]);
	if(judge(N,tmp[6],output))
	{
		printf("5\n");
		return 0;
	}

	rotation(N,tmp[7],tmp[6]);
	if(judge(N,tmp[7],output))
	{
		printf("5\n");
		return 0;
	}

	if(judge(N,input,output))
	{
		printf("6\n");
		return 0;
	}

	printf("7\n");
	return 0;
}



