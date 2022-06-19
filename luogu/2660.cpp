#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int main() {
    ll x, y, u;
    ll ans = 0;
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> x >> y;
    while (x && y) {
        u = max(x, y) / min(x, y);
        ans += 4 * min(x, y) * u;
        if (x < y) {
            y -= x * u;
        } else {
            x -= y * u;
        }
    }
    cout << ans << endl;
    return 0;
}
