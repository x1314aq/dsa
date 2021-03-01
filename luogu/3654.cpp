#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int n, m, k;
char g[105][105];

static int ok(int i, int j) {
    int ans = 0;
    bool a = true;

    for (int u = 1; u < k; ++u) {
        if (j + u >= m || g[i][j + u] != '.') {
            a = false;
            break;
        }
    }
    if (a) ans++;

    a = true;
    for (int u = 1; u < k; ++u) {
        if (i + u >= n || g[i + u][j] != '.') {
            a = false;
            break;
        }
    }
    if (a) ans++;
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m >> k;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> g[i][j];
        }
    }

    ll ans = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (g[i][j] == '.') {
                if (k == 1) ans++;
                else ans += ok(i, j);
            }
        }
    }
    cout << ans << endl;
    return 0;
}