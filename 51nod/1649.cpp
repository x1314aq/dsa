//
// 1649 齐头并进
//

#include <bits/stdc++.h>

using namespace std;

int n, m;
vector<int> a[405];
vector<int> b[405];
int c[405][405];
bool visited[405];

int bfs(bool rail) {
    int ans = 0;
    queue<int> q;

    q.push(1);
    q.push(-1);
    visited[1] = true;
    while (!q.empty()) {
        int u = q.front();
        q.pop();

        if (u == -1) {
            if (q.empty())
                return -1;
            ans++;
            q.push(-1);
            continue;
        }

        if (!rail) {
            for (int i = 0; i < a[u].size(); i++) {
                if (a[u][i] == n)
                    return ans + 1;
                if (!visited[a[u][i]]) {
                    q.push(a[u][i]);
                    visited[a[u][i]] = true;
                }
            }
        }
        else {
            for (int i = 0; i < b[u].size(); i++) {
                if (b[u][i] == n)
                    return ans + 1;
                if (!visited[b[u][i]]) {
                    q.push(b[u][i]);
                    visited[b[u][i]] = true;
                }
            }
        }
    }

    return ans;
}

int main() {
    ios::sync_with_stdio(false);

    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (i != j) c[i][j] = 1;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        c[u][v] = 2;
        c[v][u] = 2;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (c[i][j] == 1)
                b[i].push_back(j);
            else if (c[i][j] == 2)
                a[i].push_back(j);
        }
    }

    cout << bfs(c[1][n] == 2) << endl;
    return 0;
}
