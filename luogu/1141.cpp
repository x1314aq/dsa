//
// 1141 迷宫
//

#include <bits/stdc++.h>

using namespace std;

int n, m;
char g[1005][1005];
int mem[1005][1005];
int ans[1000005];

void dfs(int x, int y, int c, int ii) {
    if (x < 1 || x > n || y < 1 || y > n || mem[x][y] != 0 || g[x][y] - '0' != c)
        return;
    mem[x][y] = ii;
    ans[ii]++;
    dfs(x - 1, y, 1 - c, ii);
    dfs(x, y + 1, 1 - c, ii);
    dfs(x + 1, y, 1 - c, ii);
    dfs(x, y - 1, 1 - c, ii);
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> &g[i][1];
    for (int i = 1; i <= m; i++) {
        int x, y;
        cin >> x >> y;
        if (mem[x][y] == 0)
            dfs(x, y, g[x][y] - '0', i);
        else
            ans[i] = ans[mem[x][y]];
    }
    for (int i = 1; i <= m; i++)
        cout << ans[i] << endl;
    return 0;
}
