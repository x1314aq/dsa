#include <bits/stdc++.h>

using namespace std;
using ll = long long int;
using pii = pair<int, int>;
using pil = pair<int, ll>;
using pll = pair<ll, ll>;

int n, m;
int a[1000005];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < m; ++i) {
        int u;
        cin >> u;
        int *x = lower_bound(a, a + n, u);
        int *y = upper_bound(a, a + n, u);
        if (x == y)
            cout << -1 << ' ';
        else
            cout << ((intptr_t)x - (intptr_t)a) / sizeof(int) + 1 << ' ';
    }
    return 0;
}
