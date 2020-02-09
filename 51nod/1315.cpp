//
// 1315 合法整数集
//

#include <bits/stdc++.h>

using namespace std;
using ull = unsigned long long;

int X[35];
int s[35];

void fn(int x) {
    int c = 0;
    int a[35] = {0};
    while (x) {
        a[c] = x & 1;
        if (a[c] && !X[c])
            return;
        x >>= 1;
        c++;
    }
    for (int i = 0; i < 35; i++)
        s[i] += a[i];
}

int main() {
    int x, n;

    cin >> n >> x;
    int c = 0;
    while (x) {
        X[c++] = x & 1;
        x >>= 1;
    }

    for (int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        fn(tmp);
    }

    int ans = n;
    for (int i = 0; i < 35; i++) {
        if (X[i])
            ans = min(ans, s[i]);
    }

    cout << ans << endl;
    return 0;
}
