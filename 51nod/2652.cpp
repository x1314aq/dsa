//
// 2652 阶乘0的数量 V2
//

#include <bits/stdc++.h>

using namespace std;
using ull = unsigned long long;

ull zero(ull n) {
    ull sum = 0;

    while (n) {
        sum += n / 5;
        n /= 5;
    }
    return sum;
}

ull fn(ull k) {
    ull l = 1, r = 5e9;

    while (l + 1 < r) {
        ull mid = (l + r) / 2;
        ull num = zero(mid);
        if (num >= k)
            r = mid;
        else
            l = mid;
    }
    return r;
}

int main() {
    ull k;

    cin >> k;
    cout << fn(k) << endl;
    return 0;
}
