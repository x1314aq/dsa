//
// 1627 瞬间移动
//

#include <bits/stdc++.h>

using namespace std;
using ull = unsigned long long;

const int mod = 1e9 + 7;

ull quick_pow(ull a, ull b) {
    ull ans = 1;

    while (b) {
        if (b & 1)
            ans = (ans * a)  % mod;
        b >>= 1;
        a = (a * a) % mod;
    }
    return ans;
}

int main() {
    int m, n;
    ull a = 1, b = 1;

    cin >> m >> n;

    for (int i = 2; i <= n - 1; i++)
        b = (b * i) % mod;

    for (int i = m; i <= n - 1 + m - 1; i++)
        a = (a * i) % mod;

    cout << (a * quick_pow(b, mod - 2)) % mod << endl;
    return 0;
}
