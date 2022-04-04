#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

static vector<int> g_n[100005];
static bool g_vis[100005];

static void dfs(int x) {
    cout << x << ' ';

    if (g_n[x].empty()) {
        return;
    }

    for (auto it = g_n[x].cbegin(); it != g_n[x].cend(); ++it) {
        if (!g_vis[*it]) {
            g_vis[*it] = true;
            dfs(*it);
        }
    }
}

static void bfs(int x) {
    queue<int> q;

    q.push(x);
    while (!q.empty()) {
        int u = q.front();
        q.pop();

        cout << u << ' ';
        for (auto it = g_n[u].cbegin(); it != g_n[u].cend(); ++it) {
            if (!g_vis[*it]) {
                g_vis[*it] = true;
                q.push(*it);
            }
        }
    }
}

int main() {
    int n, m;
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        g_n[u].push_back(v);
    }

    for (int i = 1; i <= n; i++) {
        sort(g_n[i].begin(), g_n[i].end());
        g_vis[i] = false;
    }
    g_vis[1] = true;
    dfs(1);
    cout << '\n';

    for (int i = 1; i <= n; i++) {
        g_vis[i] = false;
    }
    g_vis[1] = true;
    bfs(1);
    cout.flush();
    return 0;
}