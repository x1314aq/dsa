//
// 1002 过河卒
//

#include <bits/stdc++.h>

using namespace std;
typedef unsigned long long ull;

int n, m, x, y;
ull a[25][25];

static inline bool die(int i, int j) {
    if (i == x && j == y)
        return true;
    if (abs(i - x) == 1 && abs(j - y) == 2)
        return true;
    if (abs(i - x) == 2 && abs(j - y) == 1)
        return true;
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n >> m >> x >> y;
    if (!die(0, 0))
        a[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        if (!die(i, 0))
            a[i][0] = a[i - 1][0];
    }
    for (int i = 1; i <= m; i++) {
        if (!die(0, i))
            a[0][i] = a[0][i - 1];
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            a[i][j] = a[i - 1][j] + a[i][j - 1];
            if (die(i, j))
                a[i][j] = 0;
        }
    }

    cout << a[n][m] << endl;
    return 0;
}