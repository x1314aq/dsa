/**
 * hihoCoder 1089  最短路径二
 * Floyd Algorithm
 */

#include <bits/stdc++.h>
using namespace std;

int g[105][105];
int dist[105][105];

int main() {
    int n, m;
    cin >> n >> m;

    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= n; j++)
            g[i][j] = 10000;
    for (int i = 1; i <= m; i++) {
        int u, v, d;
        cin >> u >> v >> d;
        g[u][v] = g[v][u] = min(g[u][v], d);
    }

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            dist[i][j] = (i != j ? g[i][j] : 0);

    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                if (dist[i][j] > dist[i][k] + dist[k][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++)
            cout << dist[i][j] << " ";
        cout << endl;
    }
    return 0;
}
