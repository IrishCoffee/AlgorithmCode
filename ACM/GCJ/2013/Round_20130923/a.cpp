#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

char reads[16][16] = {" "," ","double","triple","quadruple","quintuple","sextuple","septuple","octuple","nonuple","decuple"};
char number[16][16] = {"zero","one","two","three","four","five","six","seven","eight","nine"};
char phone[1024];
char tpl[1024];
int main()
{
	freopen("in","r",stdin);
	freopen("out","w",stdout);
	int T;
	int cases = 0;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%s%s",phone,tpl);
		printf("Case #%d:",++cases); 
		int tpl_len = strlen(tpl);
		int phone_len = strlen(phone);
		int flag_phone = 0;
		for(int i = 0; i < tpl_len; ++i)
		{
			int tmp = tpl[i] - '0';
			int m;
			for(m = i + 1;m < tpl_len && tpl[m] != '-'; ++m)
				tmp = tmp* 10 + (tpl[m] - '0');
			i += m - i - 1;
			for(int j = 0;j < tmp; ++j)
			{
				int k;
				for(k = j+1; k < tmp; ++k)
				{
					if(phone[k  + flag_phone] != phone[k-1 + flag_phone])
						break;
				}
				if(k - j == 1)
					printf(" %s",number[phone[j + flag_phone] - '0']);
				else if(k - j > 10)
				{
					for(int m = 0; m < k - j; ++m)
						printf(" %s",number[phone[j + flag_phone] - '0']);
				}
				else
					printf(" %s %s",reads[k - j],number[phone[j + flag_phone] - '0']);

				j = k - 1;
			}
			flag_phone += tmp;
			++i;
		}
		printf("\n");
	}
}

