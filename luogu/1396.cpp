//
// 1396 营救
//

#include <bits/stdc++.h>

using namespace std;

struct edge {
    int to, w, next;
} g[40005];
int head[10005];
int cnt;
static inline void add(int u, int v, int w) {
    cnt++;
    g[cnt].to = v;
    g[cnt].w = w;
    g[cnt].next = head[u];
    head[u] = cnt;
}

int n, m, s, t;
int dist[10005];

static bool spfa(int mid) {
    queue<int> q;

    for (int i = 1; i <= n; i++)
        dist[i] = INT_MAX;
    dist[s] = 1;
    q.push(s);
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        for (int i = head[x]; i; i = g[i].next) {
            int v = g[i].to;
            if (g[i].w <= mid) {
                if (dist[v] == INT_MAX) {
                    dist[v] = 1;
                    q.push(v);
                }
            }
        }
    }
    return dist[t] == INT_MAX ? false : true;
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n >> m >> s >> t;
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        add(u, v, w);
        add(v, u, w);
    }
    int l = 0, r = 10000;
    while (l < r) {
        int mid = (l + r) / 2;
        if (spfa(mid))
            r = mid;
        else
            l = mid + 1;
    }
    cout << l << endl;
    return 0;
}
