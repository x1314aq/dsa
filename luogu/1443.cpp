#include <bits/stdc++.h>

using namespace std;
using ll = long long int;
using pii = pair<int, int>;
using pil = pair<int, ll>;
using pll = pair<ll, ll>;

int m, n, x, y;
int g[405][405];
bool vis[405][405];

void bfs() {
    int step = 0;
    queue<pii> q;
    q.push(make_pair(x, y));
    q.push(make_pair(-1, -1));
    vis[x][y] = true;

    while (!q.empty()) {
        pii u = q.front();
        q.pop();
        x = u.first;
        y = u.second;
        if (x == -1 && y == -1) {
            if (q.empty())
                break;
            q.push(make_pair(-1, -1));
            step++;
            continue;
        }
        g[x][y] = step;
        if (x - 1 >= 1 && y - 2 >= 1 && !vis[x - 1][y - 2]) {
            q.push(make_pair(x - 1, y - 2));
            vis[x - 1][y - 2] = true;
        }
        if (x - 2 >= 1 && y - 1 >= 1 && !vis[x - 2][y - 1]) {
            q.push(make_pair(x - 2, y - 1));
            vis[x - 2][y - 1] = true;
        }
        if (x - 2 >= 1 && y + 1 <= m && !vis[x - 2][y + 1]) {
            q.push(make_pair(x - 2, y + 1));
            vis[x - 2][y + 1] = true;
        }
        if (x - 1 >= 1 && y + 2 <= m && !vis[x - 1][y + 2]) {
            q.push(make_pair(x - 1, y + 2));
            vis[x - 1][y + 2] = true;
        }
        if (x + 1 <= n && y + 2 <= m && !vis[x + 1][y + 2]) {
            q.push(make_pair(x + 1, y + 2));
            vis[x + 1][y + 2] = true;
        }
        if (x + 2 <= n && y + 1 <= m && !vis[x + 2][y + 1]) {
            q.push(make_pair(x + 2, y + 1));
            vis[x + 2][y + 1] = true;
        }
        if (x + 2 <= n && y - 1 >= 1 && !vis[x + 2][y - 1]) {
            q.push(make_pair(x + 2, y - 1));
            vis[x + 2][y - 1] = true;
        }
        if (x + 1 <= n && y - 2 >= 1 && !vis[x + 1][y - 2]) {
            q.push(make_pair(x + 1, y - 2));
            vis[x + 1][y - 2] = true;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m >> x >> y;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            g[i][j] = -1;
    g[x][y] = 0;
    bfs();
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cout << left << setw(5) << g[i][j];
        }
        cout << endl;
    }
    return 0;
}
