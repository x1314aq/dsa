//
// 4779 单源最短路径（标准版）
//

#include <bits/stdc++.h>

using namespace std;

struct edge {
    int to, w, next;
} g[200005];

int head[100005];
int cnt = 0;
void add(int u, int v, int w) {
    cnt++;
    g[cnt].to = v;
    g[cnt].w = w;
    g[cnt].next = head[u];
    head[u] = cnt;
}

int dis[100005];
bool vis[100005];
struct node {
    int v, w;
    bool operator<(const node &a) const { return w > a.w; }
};

int main() {
    int n, m, s;
    ios::sync_with_stdio(false);
    priority_queue<node> q;

    cin >> n >> m >> s;
    for (int i = 1; i <= m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        add(u, v, w);
    }

    for (int i = 1; i <= n; i++)
        dis[i] = 0x7fffffff;
    dis[s] = 0;
    q.push(node{s, 0});
    while (!q.empty()) {
        node n = q.top();
        q.pop();
        int u = n.v;
        if (vis[u])
            continue;
        vis[u] = true;
        for (int i = head[u]; i; i = g[i].next) {
            int v = g[i].to;
            if (!vis[v] && dis[v] > dis[u] + g[i].w) {
                dis[v] = dis[u] + g[i].w;
                q.push(node{v, dis[v]});
            }
        }
    }
    for (int i = 1; i <= n; i++)
        cout << dis[i] << ' ';
    cout << endl;
    return 0;
}
