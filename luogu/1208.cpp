#include <bits/stdc++.h>

using namespace std;
using ll = long long int;
using pii = pair<int, int>;
using pil = pair<int, ll>;
using pll = pair<ll, ll>;

int n, m;
pii a[5005];
int ans;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        cin >> a[i].first >> a[i].second;
    }
    sort(a, a + m);
    int i = 0;
    int v;
    while (n) {
        v = min(n, a[i].second);
        ans += v * a[i].first;
        n -= v;
        i++;
    }
    cout << ans << endl;

    return 0;
}
