//
// 2650 最短缩减路径
//

#include <bits/stdc++.h>

using namespace std;
using pii = pair<int, int>;

struct edge {
    int to;
    int w;
};
vector<edge> nodes[1010];
int n, m;
int s, t;
int visited[1010];
int dist[1010];

struct cmp {
    bool operator()(const pii &a, const pii &b) { return a.second > b.second; }
};

void dijkstra() {
    priority_queue<pii, vector<pii>, cmp> pq;

    memset(dist, 0x7f, sizeof(dist));
    dist[s] = 0;
    pq.push(make_pair(s, 0));

    while (!pq.empty()) {
        int u = pq.top().first;
        pq.pop();
        if (visited[u])
            continue;
        visited[u] = 1;
        for (int i = 0; i < nodes[u].size(); i++) {
            int v = nodes[u][i].to;
            int w = nodes[u][i].w;
            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                pq.push(make_pair(v, dist[v]));
            }
        }
    }
}

int main() {
    int ans = 0x0fffffff;
    ios::sync_with_stdio(false);

    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        nodes[u].push_back({v, w});
        nodes[v].push_back({u, w});
        nodes[u + n].push_back({v + n, w});
        nodes[v + n].push_back({u + n, w});
        nodes[u].push_back({v + n, w / 2});
        nodes[v].push_back({u + n, w / 2});
    }
    cin >> s >> t;
    dijkstra();
    cout << min(dist[t], dist[t + n]) << endl;
    return 0;
}
