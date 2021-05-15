#include <bits/stdc++.h>

using namespace std;
using ll = long long int;

int maxn;
int s[15];
int b[15];
bool vis[15];
ll ans = LLONG_MAX;

void dfs(int k, int startx, ll ss, ll sb, int n) {
    if (k == n) {
        ans = min(ans, abs(ss - sb));
        return;
    }
    for (int i = startx + 1; i <= startx + n; i++) {
        if (i >= maxn)
            continue;
        dfs(k + 1, i, ss * s[i], sb + b[i], n);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> maxn;
    for (int i = 0; i < maxn; ++i) {
        cin >> s[i] >> b[i];
    }

    for (int i = 1; i <= maxn; i++) {
        for (int j = 0; j < maxn; j++) {
            dfs(1, j, s[j], b[j], i);
        }
    }
    cout << ans << endl;
    return 0;
}
