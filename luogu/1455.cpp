//
// 1455 搭配购买
//

#include <bits/stdc++.h>

using namespace std;

int sup[10005];
long long c[10005], d[10005];
long long dp[10005];

int find(int x) {
    return sup[x] = (x == sup[x] ? x : find(sup[x]));
}

void join(int x, int y) {
    int fx = find(x);
    int fy = find(y);
    if (fx != fy) {
        sup[fx] = fy;
        c[fy] += c[fx];
        d[fy] += d[fx];
    }
}

int main() {
    int n, m, w;
    long long ans = 0;
    ios::sync_with_stdio(false);
    cin >> n >> m >> w;
    for (int i = 1; i <= n; i++) {
        cin >> c[i] >> d[i];
        sup[i] = i;
    }
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        join(u, v);
    }

    for (int i = 1; i <= n; i++) {
        if (sup[i] == i)
            for (int j = w; j >= c[i]; j--)
                dp[j] = max(dp[j], dp[j - c[i]] + d[i]);
    }

    cout << dp[w] << endl;
    return 0;
}
