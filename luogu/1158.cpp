//
// 1158 导弹拦截
//

#include <bits/stdc++.h>

using namespace std;
using ull = unsigned long long;
using pii = pair<int, int>;

static inline int sq(int a) {
    return a * a;
}

vector<pii> v;
int a1, b1, a2, b2;
ull d[100005];

bool cmp(const pii &a, const pii &b) {
    int p = sq(a.first - a1) + sq(a.second - b1);
    int q = sq(b.first - a1) + sq(b.second - b1);
    return p < q;
}

int main() {
    int n;
    ios::sync_with_stdio(false);
    cin >> a1 >> b1 >> a2 >> b2;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        v.push_back(make_pair(x, y));
    }

    sort(v.begin(), v.end(), cmp);
    for (int i = n - 1; i >= 0; i--) {
        ull t = sq(v[i].first - a2) + sq(v[i].second - b2);
        d[i] = max(d[i + 1], t);
    }

    ull ans = UINT64_MAX;
    for (int i = 0; i < n; i++) {
        ull u = sq(v[i].first - a1) + sq(v[i].second - b1);
        ans = min(ans, u + d[i + 1]);
    }
    cout << ans << endl;
    return 0;
}
