#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

static vector<int> g_w[1505];
static vector<int> g_n[1505];
static int g_in[1505];
static int g_dis[1505];

int main() {
    int n, m;
    queue<int> q;
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        g_n[u].push_back(v);
        g_w[u].push_back(w);
        g_in[v]++;
    }

    for (int i = 2; i <= n; i++) {
        g_dis[i] = -1e9;
        if (!g_in[i]) {
            q.push(i);
        }
    }

    while (!q.empty()) {
        int x = q.front();
        q.pop();
        for (int i = 0; i < g_n[x].size(); i++) {
            if (--g_in[g_n[x][i]] == 0) {
                q.push(g_n[x][i]);
            }
        }
    }
    q.push(1);
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        for (int i = 0; i < g_n[x].size(); i++) {
            if (g_dis[g_n[x][i]] < g_dis[x] + g_w[x][i]) {
                g_dis[g_n[x][i]] = g_dis[x] + g_w[x][i];
            }

            if (!--g_in[g_n[x][i]]) {
                q.push(g_n[x][i]);
            }
        }
    }
    if (g_dis[n] == -1e9)
        cout << "-1";
    else
        cout << g_dis[n];
    return 0;
}