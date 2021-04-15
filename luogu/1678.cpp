#include <bits/stdc++.h>

using namespace std;
using ll = long long int;
using pii = pair<int, int>;
using pil = pair<int, ll>;
using pll = pair<ll, ll>;

int n, m;
int a[100005];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> m >> n;
    for (int i = 0; i < m; ++i) {
        cin >> a[i];
    }
    sort(a, a + m);
    ll ans = 0;
    for (int i = 0; i < n; ++i) {
        int u;
        cin >> u;
        int *x = lower_bound(a, a + m, u);
        if (x == a + m)
            ans += u - a[m - 1];
        else if (x == a)
            ans += a[0] - u;
        else
            ans += min(*x - u, u - *(x - 1));
    }
    cout << ans << endl;
    return 0;
}
