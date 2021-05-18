#include <bits/stdc++.h>

using namespace std;
using ll = long long int;
using pii = pair<int, int>;
using pil = pair<int, ll>;
using pll = pair<ll, ll>;

int m, n, ans;
bool g[15][15];

void print() {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (g[i][j])
                cout << j << ' ';
        }
    }
    cout << endl;
}

bool ok(int x, int y) {
    for (int i = 1; i < x; i++) {
        if (g[i][y])
            return false;
        if (y - x + i >= 1 && g[i][y - x + i])
            return false;
        if (y + x - i <= n && g[i][y + x - i])
            return false;
    }
    return true;
}

void dfs(int x) {
    if (x == n + 1) {
        ans++;
        if (++m <= 3)
            print();
        return;
    }
    for (int i = 1; i <= n; i++) {
        g[x][i] = true;
        if (ok(x, i))
            dfs(x + 1);
        g[x][i] = false;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    dfs(1);
    cout << ans << endl;
    return 0;
}
