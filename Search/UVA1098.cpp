//
// Created by wrj77 on 2018/11/19.
//

#include <bits/stdc++.h>
using namespace std;
int n, m, t = 1;
int ans = 0;
int dir[4][2] = {0, 1, 0, -1, 1, 0, -1, 0};
pair<int, int> p[5];
bool vis[10][10];

inline bool in (int x, int y) {
    if(x < 0 || y < 0 || x >= n || y >= m || vis[x][y]) return 0;
    return 1;
}
inline int get(int i) { return (i+1) * n * m / 4; }

void dfs(int x, int y, int step) {
    if(x == 0 && y == 1 && step == n*m) {
        ans ++; return;
    }
    for (int i = 0; i < 4; i++) {
        int tmp = get(i) - step;
        if(tmp >= 0) {
            if(tmp < abs(x - p[i].first) + abs(y - p[i].second)) return;
        }
    }
    if(in(x-1, y) && in(x+1, y) && !in(x, y-1) && !in(x, y+1)) return ;
    if(!in(x-1, y) && !in(x+1, y) && in(x, y-1) && in(x, y+1)) return ;

    for (int i = 0; i < 4; i++) {
        int _x = x + dir[i][0];
        int _y = y + dir[i][1];
        if(!in(_x, _y) || vis[_x][_y]) continue;
        vis[_x][_y] = 1;
        dfs(_x, _y, step+1);
        vis[_x][_y] = 0;
    }
}

int main() {
    while(~scanf("%d%d", &n, &m) && n) {
        for (int i = 0; i < 3; i++) {
            scanf("%d%d", &p[i].first, &p[i].second);
        }
        if(n*m%2==1) {
            printf("Case %d: 0\n",t++);
            continue;
        }
        p[3].first = 0; p[3].second = 1;
        ans = 0;
        vis[0][0] = 1;
        dfs(0, 0, 1);
        printf("Case %d: %d\n",t++, ans);
    }
    return 0;
}