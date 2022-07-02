#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int n, m;
char g[105][105];

void fn(int i, int j) {
    queue<pii> q;
    int x[3] = {-1, 0, 1};
    int y[3] = {-1, 0, 1};

    q.push(make_pair(i, j));
    while (!q.empty()) {
        auto p = q.front();
        q.pop();
        for (int u = 0; u < 3; u++) {
            int xx = p.first + x[u];
            if (xx < 0 || xx >= n)
                continue;
            for (int v = 0; v < 3; v++) {
                int yy = p.second + y[v];
                if (yy < 0 || yy >= m)
                    continue;
                if (g[xx][yy] == 'W') {
                    g[xx][yy] = '.';
                    q.push(make_pair(xx, yy));
                }
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> g[i];
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (g[i][j] == 'W') {
                g[i][j] = '.';
                fn(i, j);
                ans++;
            }
        }
    }
    cout << ans << endl;
    return 0;
}
