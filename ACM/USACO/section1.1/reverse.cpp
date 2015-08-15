#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;

char input[1024];
int break_point[1024];
char ans[1024];
int main()
{
//	freopen("in","r",stdin);
//	freopen("out","w",stdout);
	int N,cases = 0;
	scanf("%d",&N);
	scanf("%*c");
	while(N--)
	{
		scanf("%[^\n]%*c",input);
		int num = 0;
		int len = strlen(input);
		for(int i = 0; i < len; ++i)
		{
			ans[i] = input[len - i - 1];
			if(ans[i] == ' ')
				break_point[num++] = i;
		}
		break_point[num++] = len;
		printf("Case #%d: ",++cases);
		for(int i = 0; i < num; ++i)
		{
			for(int j = break_point[i] - 1;j >= 0; --j)
			{
				if(ans[j] == ' ')
			    {
					if(i == num - 1)
						printf("\n");
					else
						printf(" ");
					break;
				}
				else
					printf("%c",ans[j]);
				if(j == 0)
					printf(" ");
			}
		}
		if(num == 1)
			printf("\n");
	}
	return 0;
}

