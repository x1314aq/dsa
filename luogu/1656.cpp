//
// 1656 炸铁路
//

#include <bits/stdc++.h>

using namespace std;
using pii = pair<int, int>;

struct edge {
    int from, to, w, next;
    bool valid;
} g[5005];

int head[155];
int cnt = 0;
void add(int u, int v, int w) {
    cnt++;
    g[cnt].from = u;
    g[cnt].to = v;
    g[cnt].w = w;
    g[cnt].next = head[u];
    g[cnt].valid = true;
    head[u] = cnt;
}

struct node {
    int v, w;
    bool operator <(const node &a) const {
        return w > a.w;
    }
};

bool dijkstra(int n) {
    int dis[155];
    bool vis[155];
    priority_queue<node> q;
    int u = 1;

    for (int i = 1; i <= n; i++) {
        dis[i] = 0x7fffffff;
        vis[i] = false;
    }
    dis[u] = 0;
    q.push(node{u, 0});
    while (!q.empty()) {
        node tmp = q.top();
        q.pop();
        u = tmp.v;
        if (vis[u]) continue;
        vis[u] = true;
        for (int i = head[u]; i; i = g[i].next) {
            if (!g[i].valid) continue;
            int v = g[i].to;
            if (!vis[v] && dis[u] + g[i].w < dis[v]) {
                dis[v] = dis[u] + g[i].w;
                q.push(node{v, dis[v]});
            }
        }
    }

    for (int i = 2; i <= n; i++)
        if (dis[i] == 0x7fffffff)
            return true;

    return false;
}

bool cmp(const pii &a, const pii &b) {
    return a.first == b.first ? a.second < b.second : a.first < b.first;
}

int main() {
    int n, m;
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        add(u, v, 1);
        add(v, u, 1);
    }

    vector<pii> ans;
    for (int i = 1; i <= cnt; i++) {
        g[i].valid = false;
        if (dijkstra(n))
            ans.push_back(make_pair(g[i].from, g[i].to));
        g[i].valid = true;
    }
    sort(ans.begin(), ans.end(), cmp);
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i].first << ' ' << ans[i].second << endl;
    return 0;
}
