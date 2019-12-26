//
// 2600 小Biu的旅行
//

#include <bits/stdc++.h>

using namespace std;
using pii = pair<int, int>;

vector<int> nodes[1005];
int n, m;
int visited[1005];
int dist[1005];

struct cmp {
    bool operator()(const pii &a, const pii &b) {
        return a.second > b.second;
    }
};


int dijkstra(int dest) {
    priority_queue<pii, vector<pii>, cmp> pq;

    memset(visited, 0, sizeof(visited));
    memset(dist, 0x0f, sizeof(dist));
    dist[1] = 0;
    pq.push(make_pair(1, 0));

    while (!pq.empty()) {
        int u = pq.top().first;
        int tmp = pq.top().second;
        pq.pop();
        if (visited[u] || tmp > dist[u])
            continue;
        visited[u] = 1;
        if (u == dest)
            break;
        for (int i = 0; i < nodes[u].size(); i++) {
            int v = nodes[u][i];
            dist[v] = min(dist[v], dist[u] + 1);
            pq.push(make_pair(v, dist[v]));
        }
    }

    return dist[dest] == 0x0f0f0f0f ? -1 : dist[dest];
}

int main() {
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        nodes[u].push_back(v);
    }

    for (int i = 2; i <= n; i++)
        cout << dijkstra(i) << endl;

    return 0;
}
