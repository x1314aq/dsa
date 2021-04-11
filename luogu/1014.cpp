//
// 1014 Cantor 表
//

#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    int l = 1, r, m;

    ios::sync_with_stdio(false);
    cin >> n;
    r = n;
    while (l < r) {
        m = l + (r - l) / 2;
        if ((m * (m + 1) / 2) >= n)
            r = m;
        else
            l = m + 1;
    }
    int a = n - l * (l - 1) / 2;
    if (l % 2 == 0)
        cout << a << '/' << l + 1 - a << endl;
    else
        cout << l + 1 - a << '/' << a;
    return 0;
}
