#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

static vector<int> g_m[100005];
static int g_ans[100005];
static bool g_vis[100005];

static void dfs(int x, int d) {
    if (g_ans[x]) {
        return;
    }
    g_ans[x] = d;
    for (auto it = g_m[x].cbegin(); it != g_m[x].cend(); ++it) {
        dfs(*it, d);
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
        g_m[v].push_back(u);
    }

    for (int i = n; i >= 1; i--) {
        dfs(i, i);
    }

    for (int i = 1; i <= n; i++) {
        cout << g_ans[i] << ' ';
    }
    cout << endl;
    return 0;
}