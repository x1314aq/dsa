//
// 3371 单源最短路径（弱化版）
//

#include <bits/stdc++.h>

using namespace std;

struct edge {
    edge():to(0),len(0) {}
    edge(int a, int b):to(a),len(b) {}
    int to, len;
};

int dis[10005];
bool inq[10005];
vector<edge> g[10005];

int main() {
    int n, m, s;
    ios::sync_with_stdio(false);
    queue<int> q;

    cin >> n >> m >> s;
    for (int i = 1; i <= n; i++)
        dis[i] = 0x7fffffff;
    dis[s] = 0;
    inq[s] = true;
    q.push(s);
    for (int i = 1; i <= m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].push_back(edge{v, w});
    }

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        inq[u] = false;
        for (int i = 0; i < g[u].size(); i++) {
            int v = g[u][i].to;
            if (dis[u] + g[u][i].len < dis[v]) {
                dis[v] = dis[u] + g[u][i].len;
                if (!inq[v]) {
                    q.push(v);
                    inq[v] = true;
                }
            }
        }
    }

    for (int i = 1; i <= n; i++)
        cout << dis[i] << ' ';
    cout << endl;
    return 0;
}
