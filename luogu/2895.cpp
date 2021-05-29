#include <bits/stdc++.h>

using namespace std;
using ll = long long int;
using pii = pair<int, int>;
using pil = pair<int, ll>;
using pll = pair<ll, ll>;

int n;
int g[305][305];
bool vis[305][305];
int dx[5] = {0, 0, 1, -1};
int dy[5] = {1, -1, 0, 0};

struct node {
    int x, y, s;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 0; i < 305; ++i) {
        for (int j = 0; j < 305; ++j) {
            g[i][j] = 10005;
        }
    }
    for (int i = 0; i < n; ++i) {
        int x, y, t;
        cin >> x >> y >> t;
        g[x][y] = min(g[x][y], t);
        for (int d = 0; d < 4; ++d) {
            if (x + dx[d] == -1 || y + dy[d] == -1)
                continue;
            g[x + dx[d]][y + dy[d]] = min(g[x + dx[d]][y + dy[d]], t);
        }
    }
    queue<node> q;
    q.push(node{0, 0, 0});
    vis[0][0] = 1;
    while (!q.empty()) {
        node u = q.front();
        q.pop();
        for (int i = 0; i < 4; ++i) {
            node v{u.x + dx[i], u.y + dy[i], u.s + 1};
            if (v.x == -1 || v.y == -1)
                continue;
            if (g[v.x][v.y] == 10005) {
                cout << v.s << endl;
                return 0;
            }
            if (v.s < g[v.x][v.y] && !vis[v.x][v.y]) {
                q.push(v);
                vis[v.x][v.y] = true;
            }
        }
    }
    cout << -1 << endl;
    return 0;
}
