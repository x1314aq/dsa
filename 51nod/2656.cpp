//
// 2656 阿克曼函数
//

#include <bits/stdc++.h>

using namespace std;
using ull = unsigned long long;

ull quick_pow(int a, int b) {
    ull ans = 1;

    while (b) {
        if (b & 1)
            ans *= a;
        a *= a;
        b >>= 1;
    }

    return ans;
}

int main() {
    int m, n;

    cin >> m >> n;
    if (m == 0)
        cout << n + 1 << endl;
    else if (m == 1)
        cout << n + 2 << endl;
    else if (m == 2)
        cout << 2 * (n + 3) - 3 << endl;
    else
        cout << quick_pow(2, n + 3) - 3 << endl;
    return 0;
}
