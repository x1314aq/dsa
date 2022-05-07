#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int gcd(int x, int y) {
    int r;
    while (y) {
        r = x % y;
        x = y;
        y = r;
    }
    return x;
}

int main() {
    int n, m;
    ll a;
    int ans = 0;
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    a = n * m;
    int x, y;
    for (x = n; x <= m; x += n) {
        y = a / x;
        if (x * y != a || gcd(x, y) != n) {
            continue;
        }
        ans++;
    }
    cout << ans << endl;
    return 0;
}