#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

void solve(int x, int y, int a, int b, int l) {
    if (l == 1)
        return;
    if (x - a <= l / 2 - 1 && y - b <= l / 2 - 1) {
        printf("%d %d 1\n", a + l / 2, b + l / 2);
        solve(x, y, a, b, l / 2);
        solve(a + l / 2 - 1, b + l / 2, a, b + l / 2, l / 2);
        solve(a + l / 2, b + l / 2 - 1, a + l / 2, b, l / 2);
        solve(a + l / 2, b + l / 2, a + l / 2, b + l / 2, l / 2);
    } else if (x - a <= l / 2 - 1 && y - b > l / 2 - 1) {
        printf("%d %d 2\n", a + l / 2, b + l / 2 - 1);
        solve(a + l / 2 - 1, b + l / 2 - 1, a, b, l / 2);
        solve(x, y, a, b + l / 2, l / 2);
        solve(a + l / 2, b + l / 2 - 1, a + l / 2, b, l / 2);
        solve(a + l / 2, b + l / 2, a + l / 2, b + l / 2, l / 2);
    } else if (x - a > l / 2 - 1 && y - b <= l / 2 - 1) {
        printf("%d %d 3\n", a + l / 2 - 1, b + l / 2);
        solve(a + l / 2 - 1, b + l / 2 - 1, a, b, l / 2);
        solve(a + l / 2 - 1, b + l / 2, a, b + l / 2, l / 2);
        solve(x, y, a + l / 2, b, l / 2);
        solve(a + l / 2, b + l / 2, a + l / 2, b + l / 2, l / 2);
    } else {
        printf("%d %d 4\n", a + l / 2 - 1, b + l / 2 - 1);
        solve(a + l / 2 - 1, b + l / 2 - 1, a, b, l / 2);
        solve(a + l / 2 - 1, b + l / 2, a, b + l / 2, l / 2);
        solve(a + l / 2, b + l / 2 - 1, a + l / 2, b, l / 2);
        solve(x, y, a + l / 2, b + l / 2, l / 2);
    }
}

int main() {
    int k, x, y, len;
    scanf("%d %d %d", &k, &x, &y);
    len = 1 << k;
    solve(x, y, 1, 1, len);
    return 0;
}
