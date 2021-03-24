#include <bits/stdc++.h>

using namespace std;
using ll = long long int;
using pii = pair<int, int>;
using pil = pair<int, ll>;
using pll = pair<ll, ll>;

int n, s, a, b;
pii x[5005];

static bool cmp(const pii &q, const pii &w) {
    return q.second < w.second;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> s >> a >> b;
    for (int i = 0; i < n; i++) {
        cin >> x[i].first >> x[i].second;
    }
    sort(x, x + n, cmp);
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if ((x[i].first <= a + b) && (x[i].second <= s)) {
            ans++;
            s -= x[i].second;
        }
    }
    cout << ans << endl;
    return 0;
}
