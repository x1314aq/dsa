#include <bits/stdc++.h>

using namespace std;
char g[55][55];
int n, m;
int ans;

int calc(int k) {
    int w = 0;
    for (int i = 1; i <= m; i++)
        if (g[k][i] != g[k][0])
            w++;
    return w;
}

void dfs(int k, int sum) {
    if (k == n) {
        g[n][0] = 'R';
        sum += calc(n);
        ans = min(ans, sum);
        return;
    }
    if (g[k - 1][0] == 'W') {
        if (k < n - 1) {
            g[k][0] = 'W';
            dfs(k + 1, sum + calc(k));
        }
        g[k][0] = 'B';
        dfs(k + 1, sum + calc(k));
    } else if (g[k - 1][0] == 'B') {
        g[k][0] = 'B';
        dfs(k + 1, sum + calc(k));
        g[k][0] = 'R';
        dfs(k + 1, sum + calc(k));
    } else {
        g[k][0] = 'R';
        dfs(k + 1, sum + calc(k));
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    ans = n * m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> g[i][j];

    g[1][0] = 'W';
    dfs(2, calc(1));
    cout << ans << endl;
    return 0;
}
