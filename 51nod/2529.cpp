//
// 2529 移动
//

#include <bits/stdc++.h>

using namespace std;
using ull = unsigned long long;

int main() {
    ull n, k, s;
    cin >> n >> k >> s;

    if (s < k || s > (n - 1) * k)
        cout << "NO" << endl;
    else
        cout << "YES" << endl;
    return 0;
}
