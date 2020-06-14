//
// 5651 基础最短路径练习题
//

#include <bits/stdc++.h>

using namespace std;

struct edge {
    int to, w, next;
} g[400005];
int head[100005];
int cnt;
void add(int u, int v, int w) {
    cnt++;
    g[cnt].to = v;
    g[cnt].w = w;
    g[cnt].next = head[u];
    head[u] = cnt;
}
int n, m, q;
int dist[100005];
bool vis[100005];

void dfs(int x) {
    vis[x] = true;
    for (int i = head[x]; i; i = g[i].next) {
        int v = g[i].to;
        if (!vis[v]) {
            dist[v] = dist[x] ^ g[i].w;
            dfs(v);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n >> m >> q;
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        add(u, v, w);
        add(v, u, w);
    }
    dfs(1);
    while (q--) {
        int x, y;
        cin >> x >> y;
        cout << (dist[x] ^ dist[y]) << endl;
    }
    return 0;
}
