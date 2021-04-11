//
// 1046 A^B Mod C
//

#include <bits/stdc++.h>

using namespace std;
using ull = unsigned long long;

int main() {
    ull a, b, c;
    cin >> a >> b >> c;

    ull res = 1;
    while (b) {
        if (b & 1)
            res = (a * res) % c;
        a = (a * a) % c;
        b >>= 1;
    }

    cout << res % c << endl;
    return 0;
}
