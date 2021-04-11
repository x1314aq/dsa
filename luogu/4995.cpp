#include <bits/stdc++.h>

using namespace std;
using ll = long long int;
using pii = pair<int, int>;
using pil = pair<int, ll>;
using pll = pair<ll, ll>;

int n;
int a[500];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    sort(a + 1, a + 1 + n);
    ll ans = 0;
    int u = 0, v;
    for (int i = 0; i < n; ++i) {
        if (i & 1) {
            v = i / 2 + 1;
        } else {
            v = n - i / 2;
        }
        ans += (a[u] - a[v]) * (a[u] - a[v]);
        u = v;
    }

    cout << ans << endl;
    return 0;
}
