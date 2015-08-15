#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
#include <stack>
using namespace std;

int R,C,M;
char map[128][128];
int cnt[128][128];
int dx[8] = {-1,-1,-1,0,0,1,1,1};
int dy[8] = {-1,0,1,-1,1,-1,0,1};
bool flag;
struct POS
{
	int x;
	int y;
};
void dfs(queue<queue<int> > &q,int n, int m)
{
	int i, j, temp;
	int a[100];
	queue<int> tmp;
	for (i = 0; i<m; i++)
	{
		a[i] = i+1;
		tmp.push(a[i]);
	}
	q.push(tmp);
	i = 0;
	while (a[i]<n-m+i+1 || i!= 0)
	{
		temp = 0;
		for (j = 0; j<m; j++)
		{
			if (a[j]>=n-m+j+1) 
			{
				temp = 1;
				break;
			}
		}
		i = j-1;
		a[i]+=1;
		if (temp)
		{
			if (i == 0)	
			{
				for (j = 1; j<m; j++)
					a[j] = a[i]+j;
			}
			a[i+1] = a[i]+1;
			temp = 0;
		}
		queue<int> tmp;
		for (j = 0; j<m; j++)	
			tmp.push(a[j]);
		q.push(tmp);
	}
}
bool in(int x,int y)
{
	return (x < R && x >= 0 && y < C && y >= 0);
}
int get_cnt(int x,int y)
{
	int ans = 0;
	for(int i = 0; i < 8; ++i)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];
		if(in(nx,ny) && map[nx][ny] == '*')
			ans++;
	}
	return ans;
}
void cal()
{
	for(int i = 0; i < R; ++i)
	{
		for(int j = 0; j < C; ++j)
		{
			if(map[i][j] == '*')
				cnt[i][j] = -1;
			else
				cnt[i][j] = get_cnt(i,j);
		}
	}
	return;
}
void generate(queue<int> s)
{
	if(flag)
	{
		for(int i = 0; i < R; ++i)
			for(int j = 0; j < C; ++j)
				map[i][j] = '.';
		while(!s.empty())
		{
			int tmp = s.front();
			tmp--;
			s.pop();
			map[tmp/C][tmp%C] = '*';
		}
	}
	else
	{
		for(int i = 0; i < R; ++i)
			for(int j = 0; j < C; ++j)
				map[i][j] = '*';
		while(!s.empty())
		{
			int tmp = s.front();
			tmp--;
			s.pop();
			map[tmp/C][tmp%C] = '.';
		}
	}
	cal();
	return;
}
bool check()
{
	for(int i = 0; i < R; ++i)
		for(int j = 0; j < C; ++j)
		{
			if(map[i][j] == '.')
				return false;
		}
	return true;
}
void print()
{
	for(int i = 0; i < R; ++i)
	{
		for(int j = 0; j < C; ++j)
			cout << map[i][j];
		cout << endl;
	}
}
void solve(int x,int y)
{
	POS tmp;
	tmp.x = x,tmp.y = y;
	queue<POS> q;
	q.push(tmp);
	map[tmp.x][tmp.y] = '#';
	while(!q.empty())
	{
		tmp = q.front();
		q.pop();
		for(int i = 0; i < 8; ++i)
		{
			int nx = tmp.x + dx[i];
			int ny = tmp.y + dy[i];
			if(!in(nx,ny))
				continue;
			if(map[nx][ny] == '*')
				continue;
			if(map[nx][ny] == '.')
			{
				map[nx][ny] = '#';
				if(cnt[nx][ny] == 0)
				{
					POS new_tmp;
					new_tmp.x = nx;
					new_tmp.y = ny;
					q.push(new_tmp);
				}
			}
		}
	}
	return;
}
void reset()
{
	for(int i = 0; i < R; ++i)
		for(int j = 0; j < C; ++j)
			if(map[i][j] != '*')
				map[i][j] = '.';
}
int main()
{
	freopen("in","r",stdin);
	freopen("out","w",stdout);
	int T,nn = 0;
	scanf("%d",&T);
	while(T--)
	{
		flag = true;
		scanf("%d%d%d",&R,&C,&M);
		printf("Case #%d:\n",++nn);
		queue<queue<int> > q_mines;
		if(M > R*C/2)
		{
			flag = false;
			dfs(q_mines,R*C,R*C-M);
		}
		else
			dfs(q_mines,R*C,M);
		while(!q_mines.empty())
		{
			queue<int> s = q_mines.front();
			q_mines.pop();
			generate(s);
			for(int i = 0; i < R; ++i)
			{
				for(int j = 0; j < C; ++j)
				{
					if(map[i][j] == '*')
						continue;
					if(cnt[i][j] == 0)
					{
						solve(i,j);
						if(check())
						{
							reset();
							map[i][j] = 'c';
							print();
							goto Lable;
						}
					}
					else
					{
						map[i][j] = '#';
						if(check())
						{
							reset();
							map[i][j] = 'c';
							print();
							goto Lable;
						}
					}
					reset();
				}
			}
		}
		printf("Impossible\n");
		continue;
Lable:
		continue;
	}
	return 0;
}
