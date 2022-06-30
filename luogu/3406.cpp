#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

struct fee {
    ll a, b, c;
};

fee f[100005];
int st[100005];

int main() {
    int n, m;
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    int u, v;
    cin >> u;
    for (int i = 1; i < m; i++) {
        cin >> v;
        st[min(u, v)]++;
        st[max(u, v)]--;
        u = v;
    }
    for (int i = 1; i < n; i++) {
        cin >> f[i].a >> f[i].b >> f[i].c;
    }
    ll ans = 0;
    ll cur = 0;
    for (int i = 1; i <= n; i++) {
        cur += st[i];
        if (cur != 0) {
            ans += min(cur * f[i].a, cur * f[i].b + f[i].c);
        }
    }
    cout << ans << endl;
    return 0;
}
