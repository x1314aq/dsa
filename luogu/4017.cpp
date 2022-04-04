#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int mod = 80112002;

vector<int> g_n[5005];
int g_in[5005];
bool g_vis[5005];
int g_mem[5005];

void dfs(int x) {
    if (g_n[x].empty()) {
        g_mem[x] = 1;
        return;
    }

    if (g_mem[x]) {
        return;
    }

    for (int i = 0; i < g_n[x].size(); i++) {
        if (!g_vis[g_n[x][i]]) {
            g_vis[g_n[x][i]] = true;
            dfs(g_n[x][i]);
            g_vis[g_n[x][i]] = false;
        }
        g_mem[x] = (g_mem[x] + g_mem[g_n[x][i]]) % mod;
    }
}

int main() {
    int n, m;
    int ans = 0;
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int a, b;
        cin >> a >> b;
        g_n[a].push_back(b);
        g_in[b]++;
    }

    for (int i = 1; i <= n; i++) {
        if (g_in[i] == 0) {
            g_vis[i] = true;
            dfs(i);
            g_vis[i] = false;
            ans = (ans + g_mem[i]) % mod;
        }
    }
    cout << ans << endl;
    return 0;
}