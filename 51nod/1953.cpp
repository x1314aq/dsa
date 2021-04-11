//
// 1953 物理地址查询
//

#include <bits/stdc++.h>

using namespace std;

int matrix[105][105];
vector<int> vs[105];
int dist[105];
bool visited[105];
int n;

int min_dist(int dest) {
    for (int i = 2; i <= n; i++)
        dist[i] = 10000000;
    memset(visited, 0, sizeof(visited));

    int u = 1, v;
    for (int i = 0; i < vs[u].size(); i++) {
        v = vs[u][i];
        dist[v] = matrix[u][v];
    }
    visited[u] = true;
    while (u != dest) {
        int tmp = 10000000;
        for (int i = 2; i <= n; i++) {
            if (!visited[i] && dist[i] < tmp) {
                u = i;
                tmp = dist[i];
            }
        }

        visited[u] = true;
        for (int i = 0; i < vs[u].size(); i++) {
            v = vs[u][i];
            if (!visited[v])
                dist[v] = min(dist[v], dist[u] + matrix[u][v]);
        }
    }
    return dist[dest];
}

int main() {
    cin >> n;
    for (int i = 2; i <= n; i++) {
        for (int j = 1; j < i; j++) {
            string s;

            cin >> s;
            if (s[0] != 'x') {
                vs[i].push_back(j);
                vs[j].push_back(i);
                matrix[i][j] = matrix[j][i] = stoi(s);
            } else {
                matrix[i][j] = matrix[j][i] = 100000;
            }
        }
    }

    int ans = 0;
    for (int i = 2; i <= n; i++)
        ans = max(ans, min_dist(i));

    cout << ans << endl;
    return 0;
}
