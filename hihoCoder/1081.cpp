/**
 * hihoCoder 1081  最短路径一
 * Dijkstra
 */

#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

int g[1005][1005];
int vis[1005];
int dist[1005];

int main() {
    int n, m, s, t;
    cin >> n >> m >> s >> t;
    for (int i = 0; i < 1005; i++)
        for (int j = 0; j < 1005; j++)
            g[i][j] = 10000;
    for (int i = 1; i <= m; i++) {
        int u, v, d;
        cin >> u >> v >> d;
        g[u][v] = g[v][u] = min(g[u][v], d);
    }

    for (int i = 1; i <= n; i++)
        dist[i] = g[s][i];
    dist[s] = 0;
    vis[s] = 1;
    for (int i = 1; i <= n; i++) {
        int shortest = 0x7fffffff;
        int u = s;
        for (int j = 1; j <= n; j++) {
            if (!vis[j] && dist[j] < shortest) {
                u = j;
                shortest = dist[j];
            }
        }
        vis[u] = 1;
        for (int j = 1; j <= n; j++) {
            if (!vis[j] && g[u][j] < 10000)
                dist[j] = min(dist[j], dist[u] + g[u][j]);
        }
    }

    cout << dist[t] << endl;
    return 0;
}
