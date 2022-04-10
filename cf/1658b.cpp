#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int main() {
    int n, t;
    const int mod = 998244353;
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    while (t--) {
        cin >> n;
        if (n & 1) {
            cout << "0\n";
        } else {
            ll ans = 1;
            for (int i = 2; i <= n / 2; i++) {
                ans = (ans * i * i) % mod;
            }
            cout << ans << '\n';
        }
    }
    cout.flush();
    return 0;
}