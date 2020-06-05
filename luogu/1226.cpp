//
// 1226 快速幂｜｜取余运算
//

#include <bits/stdc++.h>

using namespace std;
using ull = unsigned long long;

int main() {
    ios::sync_with_stdio(false);
    ull a, n, m;
    ull ans = 1;

    cin >> a >> n >> m;
    cout << a << '^' << n << " mod " << m << '=';
    while (n) {
        if (n & 1)
            ans = ans * a % m;
        a = a * a % m;
        n >>= 1;
    }
    cout << (ans % m) << endl;
    return 0;
}
