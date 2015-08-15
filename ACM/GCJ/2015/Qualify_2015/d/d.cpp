#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;
char name[2][16] = {"RICHARD","GABRIEL"};
int main()
{
	freopen("in.txt","r",stdin);
	freopen("d_out.txt","w",stdout);
	int T;
	int cas = 0;
	int X,R,C;
	int winner;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d%d",&X,&R,&C);
		int RC = R * C;
		if(RC % X != 0)
		{
			winner = 0;
			goto print;
		}
		winner = 0;

		if(X == 1 || X == 2)
			winner = 1;
		else if(X == 3)
		{
			if(RC == 6 || RC == 9 || RC == 12)
				winner = 1;
		}
		else 
		{
			if(RC == 16 || RC == 12)
				winner = 1;
		}
print:printf("Case #%d: %s\n",++cas,name[winner]);
	}
	return 0;
}
