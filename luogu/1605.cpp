#include <bits/stdc++.h>

using namespace std;
using ll = long long int;
using pii = pair<int, int>;
using pil = pair<int, ll>;
using pll = pair<ll, ll>;

int n, m, t;
int sx, sy, fx, fy;
bool g[10][10];
int ans;

void dfs(int x, int y) {
    if (x == fx && y == fy) {
        ans++;
        return;
    }
    g[x][y] = true;
    if (y - 1 >= 1 && !g[x][y - 1])
        dfs(x, y - 1);
    if (y + 1 <= m && !g[x][y + 1])
        dfs(x, y + 1);
    if (x - 1 >= 1 && !g[x - 1][y])
        dfs(x - 1, y);
    if (x + 1 <= n && !g[x + 1][y])
        dfs(x + 1, y);
    g[x][y] = false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m >> t >> sx >> sy >> fx >> fy;
    for (int i = 1; i <= t; i++) {
        int x, y;
        cin >> x >> y;
        g[x][y] = true;
    }
    dfs(sx, sy);
    cout << ans << endl;
    return 0;
}
