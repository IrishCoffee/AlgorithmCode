#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
const double eps = 1e-4;
struct NODE
{
	double x,y;
}node[1024],mean1,mean2;
int cluster[1024];
double dis(NODE a,NODE b)
{
	return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}
int n;
int main()
{
	freopen("in","r",stdin);
	bool changed = true;
	memset(cluster,0,sizeof(cluster));
	scanf("%d",&n);
	for(int i = 0; i < n; ++i)
		scanf("%lf%lf",&node[i].x,&node[i].y);
	scanf("%lf%lf%lf%lf",&mean1.x,&mean1.y,&mean2.x,&mean2.y);
	while(changed)
	{
		changed = false;
		for(int i = 0; i < n; ++i)
		{
			if((dis(node[i],mean1) - dis(node[i],mean2)) < eps)
			{
				if(cluster[i] != 1)
				{
					cluster[i] = 1;
					changed = true;
				}
			}
			else
			{
				if(cluster[i] != 2)
				{
					cluster[i] = 2;
					changed = true;
				}
			}
		}
		if(!changed)
			break;
		double tmp1_x = 0,tmp1_y = 0,tmp2_x = 0,tmp2_y = 0;
		int num1 = 0,num2 = 0;
		for(int i = 0; i < n; ++i)
		{
			if(cluster[i] == 1)
			{
				num1++;
				tmp1_x += node[i].x;
				tmp1_y += node[i].y;
			}
			else
			{
				num2++;
				tmp2_x += node[i].x;
				tmp2_y += node[i].y;
			}
		}
		mean1.x = tmp1_x / num1;
		mean1.y = tmp1_y / num1;
		mean2.x = tmp2_x / num2;
		mean2.y = tmp2_y / num2;
	}
	printf("Cluster1: mean: %.4lf %.4lf\n",mean1.x,mean1.y);
	for(int i = 0; i < n; ++i)
		if(cluster[i] == 1)
			printf("x%d:(%.0lf,%.0lf) ",i+1,node[i].x,node[i].y);
	printf("\nCluster2: mean: %.3lf %.3lf\n",mean2.x,mean2.y);
	for(int i = 0; i < n; ++i)
		if(cluster[i] == 2)
			printf("x%d:(%.0lf,%.0lf) ",i+1,node[i].x,node[i].y);
	printf("\n");
	return 0;
}
