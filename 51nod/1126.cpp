//
// 1126 求递推序列的第N项
//

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const ll mod = 7;

ll a[2][2] = {
    {1, 1},
    {1, 0},
};

void matrix_multiply(ll ans[2][2]) {
    ll c[2][2] = {
        {ans[0][0], ans[0][1]},
        {ans[1][0], ans[1][1]},
    };

    ans[0][0] = ((c[0][0] * a[0][0] % mod) + (c[0][1] * a[1][0] % mod)) % mod;
    ans[0][1] = ((c[0][0] * a[0][1] % mod) + (c[0][1] * a[1][1] % mod)) % mod;
    ans[1][0] = ((c[1][0] * a[0][0] % mod) + (c[1][1] * a[1][0] % mod)) % mod;
    ans[1][1] = ((c[1][0] * a[0][1] % mod) + (c[1][1] * a[1][1] % mod)) % mod;
}

void matrix_square() {
    ll c[2][2] = {
        {a[0][0], a[0][1]},
        {a[1][0], a[1][1]},
    };

    a[0][0] = ((c[0][0] * c[0][0] % mod) + (c[0][1] * c[1][0] % mod)) % mod;
    a[0][1] = ((c[0][0] * c[0][1] % mod) + (c[0][1] * c[1][1] % mod)) % mod;
    a[1][0] = ((c[1][0] * c[0][0] % mod) + (c[1][1] * c[1][0] % mod)) % mod;
    a[1][1] = ((c[1][0] * c[0][1] % mod) + (c[1][1] * c[1][1] % mod)) % mod;
}

int main() {
    unsigned int n;

    cin >> a[0][0] >> a[0][1] >> n;

    if (n == 1 || n == 2) {
        cout << 1 << endl;
        return 0;
    }

    n -= 2;

    ll ans[2][2] = {
        {1, 0},
        {0, 1},
    };

    while (n) {
        if (n & 1)
            matrix_multiply(ans);
        n >>= 1;
        matrix_square();
    }

    cout << (ans[0][0] + ans[0][1] + mod) % mod << endl;
    return 0;
}
