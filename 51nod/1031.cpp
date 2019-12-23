//
// 1031 骨牌覆盖
//

#include <bits/stdc++.h>

using namespace std;
using ull = unsigned long long;

const int mod = 1e9+7;

int main() {
    int n;
    ull a = 1, b = 2;

    cin >> n;
    if (n == 1)
        cout << 1 << endl;
    else if (n == 2)
        cout << 2 << endl;
    else {
        ull c;
        for (int i = 3; i <= n; i++) {
            c = (a + b + mod) % mod;
            a = b;
            b = c;
        }
        cout << c << endl;
    }
    return 0;
}
