#include <bits/stdc++.h>

using namespace std;
using ll = long long int;
using pii = pair<int, int>;
using pil = pair<int, ll>;
using pll = pair<ll, ll>;

int n, c;
int a[200005];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> c;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a, a + n);
    ll ans = 0;
    for (int i = 0; i < n; ++i) {
        int u = a[i] - c;
        int *x = lower_bound(a, a + n, u);
        int *y = upper_bound(a, a + n, u);
        ans += ((intptr_t)y - (intptr_t)x) / sizeof(int);
    }
    cout << ans << endl;
    return 0;
}
