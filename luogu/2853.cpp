#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

static int g_a[1005];
static vector<int> g_n[1005];
static int g_cnt[1005];
static bool g_vis[1005];

static void dfs(int x) {
    g_vis[x] = true;
    g_cnt[x]++;
    for (auto it = g_n[x].cbegin(); it != g_n[x].cend(); ++it) {
        if (!g_vis[*it]) {
            dfs(*it);
        }
    }
}

int main() {
    int k, n, m;
    int ans = 0;
    queue<int> q;
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> k >> n >> m;
    for (int i = 1; i <= k; i++) {
        cin >> g_a[i];
    }

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        g_n[u].push_back(v);
    }

    for (int i = 1; i <= k; i++) {
        for (int i = 1; i <= n; i++) {
            g_vis[i] = false;
        }
        dfs(g_a[i]);
    }

    for (int i = 1; i <= n; i++) {
        if (g_cnt[i] == k) {
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}