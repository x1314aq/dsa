#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    int n, m;
    long ans1 = 0, ans2 = 0;
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            int a = (n + 1 -i) * (m + 1 - j);
            if (i == j) ans1 += a;
            ans2 += a;
        }
    }
    cout << ans1 << ' ' << ans2 - ans1 << endl;
    return 0;
}
