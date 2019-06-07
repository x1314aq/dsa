/**
 * hihoCoder 1143 骨牌覆盖问题一
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int mod = 19999997;

/* 递推公式，时间复杂度O(n) */
long fib(int n) {
    if(n == 1)
        return 1;
    if(n == 2)
        return 2;

    long a = 1, b = 2;
    long res;
    for(int i = 3; i <= n; i++) {
        res = (a + b) % mod;
        a = b;
        b = res;
    }
    return res;
}

/* 矩阵快速乘法，时间复杂度 O(logN) */
vector<long> mul(vector<long> &a, vector<long> &b) {
    vector<long> res(4);
    res[0] = (a[0] * b[0] + a[1] * b[2]) % mod;
    res[1] = (a[0] * b[1] + a[1] * b[3]) % mod;
    res[2] = (a[2] * b[0] + a[3] * b[2]) % mod;
    res[3] = (a[2] * b[1] + a[3] * b[3]) % mod;
    return res;
}

int main() {
    unsigned int n;
    cin >> n;
    if(n == 1) {
        cout << 1 << endl;
        return 0;
    }
    if(n == 2) {
        cout << 2 << endl;
        return 0;
    }
    n -= 2;
    vector<long> a = {0, 1, 1, 1};
    vector<long> res = {1, 0, 0, 1};

    for(; n; n >>= 1) {
        if(n & 1)
            res = mul(res, a);
        a = mul(a, a);
    }
    cout << (res[1] + 2 * res[3]) % mod << endl;
    return 0;
}
