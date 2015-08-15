#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <string>
using namespace std;

char input[1024];
char sentence_id[1024];
char parse_status[1024];
char previous_id[1024];
char fom[1024];
int main()
{
	freopen("in","r",stdin);
	freopen("out","w",stdout);
	bool flag = false;
	bool id_flag = false;
	while(gets(input) != NULL)
	{
		if(input[0] == '\0')
			flag = true;
		else if(input[0] != '\0' && flag)
		{
			sscanf(input,"%*s%*s%*s%s%s%s",sentence_id,parse_status,fom);
			if(parse_status[18] == 'y') // status = empty
				continue;
			if(id_flag)
			{
				if(strcmp(previous_id,sentence_id) != 0)
					printf("\n");
			}
			else
				id_flag = true;
			strcpy(previous_id,sentence_id);
			int len = strlen(fom);
			for(int i = 5; i < len - 1; ++i)
				printf("%c",fom[i]);
			printf("\n");
			flag = false;
		}
		else 
			flag = false;
	}
	return 0;
}
