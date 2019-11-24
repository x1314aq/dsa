//
// 2651 区间和的和
//

#include <bits/stdc++.h>

using namespace std;
using ull = unsigned long long;

const ull mod = 1e9 + 7;
ull n;

int main() {
    ull ans = 0;

    cin >> n;
    for (ull i = 1; i <= n; i++) {
        ull x;
        cin >> x;
        ans += x * i * (n + 1 - i) % mod;
        ans = ans >= mod ? ans - mod : ans;
    }

    cout << ans << endl;
    return 0;
}
