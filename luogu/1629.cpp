//
// 1629 邮递员送信
//

#include <bits/stdc++.h>

using namespace std;
using ull = unsigned long long;
using pii = pair<int, int>;

struct edge {
    int to, w, next;
} g[100005], rg[100005];
int head[1005], rhead[1005];
int cnt;
void add(int u, int v, int w) {
    cnt++;
    g[cnt].to = v;
    g[cnt].w = w;
    g[cnt].next = head[u];
    head[u] = cnt;
    rg[cnt].to = u;
    rg[cnt].w = w;
    rg[cnt].next = rhead[v];
    rhead[v] = cnt;
}

struct node {
    int u, d;
    bool operator<(const node &a) const { return d > a.d; }
};

int n, m;
int dist[1005], rdist[1005];
bool vis[1005];

void dijkstra() {
    priority_queue<node> q;
    int u = 1;

    for (int i = 1; i <= n; i++) {
        dist[i] = 0x7fffffff;
        vis[i] = false;
    }
    dist[u] = 0;
    q.push(node{u, 0});
    while (!q.empty()) {
        u = q.top().u;
        q.pop();
        if (vis[u])
            continue;
        vis[u] = true;
        for (int i = head[u]; i; i = g[i].next) {
            int v = g[i].to;
            if (dist[u] + g[i].w < dist[v]) {
                dist[v] = dist[u] + g[i].w;
                q.push(node{v, dist[v]});
            }
        }
    }
}

void reverse_dijkstra() {
    priority_queue<node> q;
    int u = 1;

    for (int i = 1; i <= n; i++) {
        rdist[i] = 0x7fffffff;
        vis[i] = false;
    }
    rdist[u] = 0;
    q.push(node{u, 0});
    while (!q.empty()) {
        u = q.top().u;
        q.pop();
        if (vis[u])
            continue;
        vis[u] = true;
        for (int i = rhead[u]; i; i = rg[i].next) {
            int v = rg[i].to;
            if (rdist[u] + rg[i].w < rdist[v]) {
                rdist[v] = rdist[u] + rg[i].w;
                q.push(node{v, rdist[v]});
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        add(u, v, w);
    }
    dijkstra();
    reverse_dijkstra();
    ull ans = 0;
    for (int i = 2; i <= n; i++)
        ans += dist[i] + rdist[i];
    cout << ans << endl;
    return 0;
}
