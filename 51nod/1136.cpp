//
// 1136 欧拉函数
//

#include <bits/stdc++.h>

using namespace std;
using ull = unsigned long long;

int main() {
    ull n, ans;

    cin >> n;
    ans = n;

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
    cout << ans << endl;
    return 0;
}
