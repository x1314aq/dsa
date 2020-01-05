//
// 1256 乘法逆元
//

#include <bits/stdc++.h>

using namespace std;
using ull = unsigned long long;

ull phi(ull n) {
    ull ans = n;

    for (ull i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            ans = ans - ans / i;
            do {
                n /= i;
            } while (n % i == 0);
        }
    }
    if (n > 1)
        ans = ans - ans / n;
    return ans;
}

int main() {
    ull m, n;
    ull tmp;

    cin >> m >> n;
    tmp = phi(n) - 1;

    ull ans = 1;
    while (tmp) {
        if (tmp & 1)
            ans = ans * m % n;
        m = m * m % n;
        tmp >>= 1;
    }
    cout << ans << endl;
    return 0;
}
