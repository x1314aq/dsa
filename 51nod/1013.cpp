//
// 1013 3的幂的和
//

#include <bits/stdc++.h>

using namespace std;
using ull = unsigned long long;
ull const mod = 1e9 + 7;

ull qpow(ull a, ull n) {
    ull ans = 1;

    while (n) {
        if (n & 1)
            ans = ans * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return ans;
}

int main() {
    int n;
    cin >> n;
    ull a = qpow(3, n + 1) - 1;
    ull b = qpow(2, mod - 2);
    cout << (a * b % mod) << endl;
    return 0;
}
