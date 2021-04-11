/**
 * hihoCoder 1093  最短路径三
 * Shortest Path Faster Algorithm
 */

#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

struct vertex {
    unordered_map<int, int> to;
};

vertex g[100005];
bool in_queue[100005];
int dist[100005];

int main() {
    int n, m, s, t;
    cin >> n >> m >> s >> t;

    for (int i = 1; i <= m; i++) {
        int u, v, d;
        cin >> u >> v >> d;
        if (g[u].to[v])
            g[u].to[v] = g[v].to[u] = min(g[u].to[v], d);
        else {
            g[u].to[v] = g[v].to[u] = d;
        }
    }

    for (int i = 1; i <= n; i++)
        dist[i] = 10000;
    dist[s] = 0;
    queue<int> q;
    q.push(s);
    in_queue[s] = true;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        in_queue[u] = false;
        for (auto it = g[u].to.begin(); it != g[u].to.end(); ++it) {
            if (dist[it->first] > dist[u] + it->second) {
                dist[it->first] = dist[u] + it->second;
                if (!in_queue[it->first]) {
                    q.push(it->first);
                    in_queue[it->first] = true;
                }
            }
        }
    }

    cout << dist[t] << endl;
    return 0;
}
