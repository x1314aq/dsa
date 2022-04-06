#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

static int g_t[205];
static int g_dis[205][205];

static void update(int k, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (g_dis[i][j] > g_dis[i][k] + g_dis[k][j]) {
                g_dis[i][j] = g_dis[i][k] + g_dis[k][j];
                g_dis[j][i] = g_dis[i][j];
            }
        }
    }
}

int main() {
    int n, m, q, now;
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> g_t[i];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            g_dis[i][j] = 1e9;
        }
    }
    for (int i = 0; i < n; i++) {
        g_dis[i][i] = 0;
    }
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        g_dis[u][v] = w;
        g_dis[v][u] = w;
    }
    cin >> q;
    now = 0;
    for (int i = 0; i < q; i++) {
        int u, v, t;
        cin >> u >> v >> t;
        while (now < n && g_t[now] <= t) {
            update(now, n);
            now++;
        }
        if (g_t[u] > t || g_t[v] > t) {
            cout << -1;
        } else {
            if (g_dis[u][v] == 1e9) {
                cout << -1;
            } else {
                cout << g_dis[u][v];
            }
        }
        cout << '\n';
    }
    cout.flush();
    return 0;
}