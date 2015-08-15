#include <iostream>
#include <cstdio>
#include <cstring>
#include <stack>
using  namespace std;

int id(char c)
{
	if(c == 'r')
		return 0;
	if(c == 'y')
		return 1;
	else
		return 2;
}
int cnt[3];
char ss[1024];
int main()
{
	memset(cnt,0,sizeof(cnt));
	gets(ss);
	int len = strlen(ss);
	bool colored = false;
	stack<int> color;
	int current_color = -1;
	for(int i = 0; i < len; ++i)
	{
		if(ss[i] == '<' && ss[i+1] != '/')
		{
			colored = true;
			int color_id = id(ss[i+1]);
			if(current_color != -1)
				color.push(current_color);
			current_color = color_id;
			while(ss[i] != '>')
				i++;
		}
		else if(ss[i] >= 'a' && ss[i] <= 'z' && colored)
			cnt[current_color]++;
		else if(ss[i] == '<' && ss[i+1] == '/')
		{
			if(!color.empty())
			{
				current_color = color.top();
				color.pop();
			}
			else
			{
				current_color = -1;
				colored = false;
			}
			while(ss[i] != '>')
				i++;
		}
	}
	printf("%d %d %d\n",cnt[0],cnt[1],cnt[2]);	
	return 0;
}






