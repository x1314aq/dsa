//
// 1147 连续自然数的和
//

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll n;

static inline ll s(ll x) {
    return x * (x + 1) / 2;
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    for (ll i = 1; i <= n / 2; i++) {
        ll s0 = s(i - 1);
        ll l = i, r = n;
        while (l < r) {
            ll m = l + (r - l) / 2;
            ll sm = s(m) - s0;
            if (sm >= n)
                r = m;
            else
                l = m + 1;
        }
        if (s(l) - s0 == n) {
            cout << i << ' ' << l << endl;
        }
    }
    return 0;
}