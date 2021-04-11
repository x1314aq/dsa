#include <bits/stdc++.h>

using namespace std;
using ll = long long int;
using pii = pair<int, int>;
using pil = pair<int, ll>;
using pll = pair<ll, ll>;
using pdi = pair<double, int>;

int n, t;
pdi a[105];

int main() {
    double ans = 0.0;
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> t;
    for (int i = 0; i < n; ++i) {
        double d;
        cin >> a[i].second >> d;
        a[i].first = d / (double)a[i].second;
    }
    sort(a, a + n);
    for (int i = n - 1; i >= 0; --i) {
        if (t <= a[i].second) {
            ans += a[i].first * t;
            break;
        }
        ans += a[i].first * a[i].second;
        t -= a[i].second;
    }
    cout << fixed << setprecision(2) << ans << endl;
    return 0;
}
