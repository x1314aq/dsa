#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int n;
int g[35][35];

static void dfs(int x, int y) {
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};

    if (x < 0 || x > n + 1 || y < 0 || y > n + 1 || g[x][y] != 0) {
        return;
    }
    g[x][y] = 2;
    for (int i = 0; i < 4; i++) {
        dfs(x + dx[i], y + dy[i]);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> g[i][j];
        }
    }
    dfs(0, 0);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << 2 - g[i][j] << ' ';
        }
        cout << '\n';
    }
    cout.flush();
    return 0;
}
