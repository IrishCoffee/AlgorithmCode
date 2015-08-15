#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int main()
{
	freopen("in","r",stdin);
	freopen("out","w",stdout);
	int T,N1,N2,nn = 0;
	int num1[4][4],num2[4][4];
	bool flag[32];
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&N1);
		for(int i = 0 ; i < 4; ++i)
			for(int j = 0; j < 4; ++j)
				scanf("%d",&num1[i][j]);
		scanf("%d",&N2);
		for(int i = 0 ; i < 4; ++i)
			for(int j = 0; j < 4; ++j)
				scanf("%d",&num2[i][j]);
		memset(flag,false,sizeof(flag));
		--N1,--N2;
		for(int i = 0; i < 4; ++i)
			flag[num1[N1][i]] = true;
		bool found = false;
		int ans = 0;
		for(int i = 0; i < 4; ++i)
		{
			if(flag[num2[N2][i]])
			{
				if(found == false)
				{
					found = true;
					ans = num2[N2][i];
				}
				else
				{
					ans = -1;//duplicate
					break;
				}
			}
		}
		printf("Case #%d: ",++nn); 
		if(ans > 0)
			printf("%d\n",ans);
		else if(ans == -1)
			printf("Bad magician!\n");
		else
			printf("Volunteer cheated!\n");
	}
		return 0;
}
