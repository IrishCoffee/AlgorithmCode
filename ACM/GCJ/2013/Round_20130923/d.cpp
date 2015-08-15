#include<iostream>
#include<cstdio>
#include<cmath>
#include<memory.h>
#include<vector>
#include<string>
#include<queue>

using namespace std;

#define Clear(f, nr) memset(f, nr, sizeof(f))
const int SIZE = 105;
const int INF = 1 << 30;

char G[SIZE][SIZE];
int n;
bool vis[SIZE][SIZE][4];
int cnt;
bool flag;
int rec[SIZE * SIZE];
int ans[SIZE * SIZE];
int etx, ety;

void dfs(int x, int y, int dir, int step)
{
    if(flag || vis[x][y][dir]) return;
    rec[step] = dir;
    if(x == etx && y == ety) {
        cnt = step;
        flag = 1;
        for(int i = 0; i <= step; i ++)
            ans[i] = rec[i];
        return ;
    }
    vis[x][y][dir] = 1;

    if(dir == 1){
        if(G[x - 1][y] == '.') dfs(x - 1, y, 4, step + 1);
        else if(G[x][y + 1] == '.') dfs(x, y + 1, 1, step + 1);
        else if(G[x + 1][y] == '.') dfs(x + 1, y, 2, step + 1);
        else if(G[x][y - 1] == '.') dfs(x, y - 1, 3, step + 1);
        else return ;
    }
    else if(dir == 2) {
        if(G[x][y + 1] == '.') dfs(x, y + 1, 1, step + 1);
        else if(G[x + 1][y] == '.') dfs(x + 1, y, 2, step + 1);
        else if(G[x][y - 1] == '.') dfs(x, y - 1, 3, step + 1);
        else if(G[x - 1][y] == '.') dfs(x - 1, y, 4, step + 1);
        else return;
    }
    else if(dir == 3){
        if(G[x + 1][y] == '.') dfs(x + 1, y, 2, step + 1);
        else if(G[x][y - 1] == '.') dfs(x, y - 1, 3, step + 1);
        else if(G[x - 1][y] == '.') dfs(x - 1, y, 4, step + 1);
        else if(G[x][y + 1] == '.') dfs(x, y + 1, 1, step + 1);
        else return ;
    }
    else {
        if(G[x][y - 1] == '.') dfs(x, y - 1, 3, step + 1);
        else if(G[x - 1][y] == '.') dfs(x - 1, y, 4, step + 1);
        else if(G[x][y + 1] == '.') dfs(x, y + 1, 1, step + 1);
        else if(G[x + 1][y] == '.') dfs(x + 1, y, 2, step + 1);
        else return ;
    }
    return ;
}

int main()
{
    freopen("in", "r", stdin);
    freopen("out", "w", stdout);
    int T, n, st, et,i;
    int gg = 0;
    cin >> T;
    while(T --) {
        cin >> n;
        for(i = 1; i <= n; i ++)
            for(int j = 1; j <= n; j ++)
                cin >> G[i][j];
        cin >> st >> et >> etx >> ety;
        for(i = 0; i <= n + 1; i ++)
            G[0][i] = G[n + 1][i] = G[i][0] = G[i][n + 1] = '#';
        Clear(vis, 0);
        cnt = 0;
        flag = 0;
        int initFlag;
        if(st == 1){
            if(et == 1) initFlag = 1;
            else initFlag = 2;
        }
        else {
            if(et == 1) initFlag = 4;
            else initFlag = 3;
        }
        //cout << "init" << initFlag << endl;
        if(G[st][et] == '#') goto X;
        //vis[st][et][initFlag] = 1;
        dfs(st, et, initFlag, 0);
X:        printf("Case #%d: ", ++ gg);
        if(!flag) {
            puts("Edison ran out of energy.");
            continue;
        }
        cout << cnt << endl;
        for(int i = 1; i <= cnt; i ++) {
            if(ans[i] == 1) printf("E");
            else if(ans[i] == 2) printf("S");
            else if(ans[i] == 3) printf("W");
            else  printf("N");
        }
        puts("");
    }
}
