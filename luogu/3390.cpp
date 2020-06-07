//
// 3390 矩阵快速幂
//

#include <bits/stdc++.h>

using namespace std;
using ull = unsigned long long;

const int mod = 1e9 + 7;

int n;
ull mat[105][105];
ull ans[105][105];

static void matrix_multiply() {
    ull a[105][105];
    memcpy(a, ans, sizeof(ans));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            ans[i][j] = 0;
            for (int k = 0; k < n; k++)
                ans[i][j] += (a[i][k] * mat[k][j] % mod);
            ans[i][j] %= mod;
        }
    }
}

static void matrix_square() {
    ull a[105][105];
    memcpy(a, mat, sizeof(mat));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            mat[i][j] = 0;
            for (int k = 0; k < n; k++)
                mat[i][j] += (a[i][k] * a[k][j] % mod);
            mat[i][j] %= mod;
        }
    }
}

int main() {
    ull k;
    ios::sync_with_stdio(false);
    cin >> n >> k;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> mat[i][j];

    for (int i = 0; i < n; i++)
        ans[i][i] = 1;
    
    while (k) {
        if (k & 1)
            matrix_multiply();
        matrix_square();
        k >>= 1;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cout << ans[i][j] << ' ';
        cout << endl;
    }
    return 0;
}
