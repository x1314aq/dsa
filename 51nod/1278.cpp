//
// 1278 相离的圆
//

#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pll = pair<ll, ll>;

bool cmp(const pll &a, const pll &b) {
    return a.first < b.first ? true : (a.first == b.first ? a.second < b.second : false);
}

pll nodes[50005];
int n;

int bs(int i) {
    int l = i, r = n;
    int mid;
    ll target = nodes[i].second;

    while (l + 1 < r) {
        mid = (l + r) / 2;
        ll tmp = nodes[mid].first;
        if (tmp <= target)
            l = mid;
        else
            r = mid;
    }
    return r;
}

int main() {
    int ans = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        ll c, r;
        cin >> c >> r;
        nodes[i].first = c - r;
        nodes[i].second = c + r;
    }

    sort(nodes, nodes + n, cmp);
    for (int i = 0; i < n; i++)
        ans += n - bs(i);

    cout << ans << endl;
    return 0;
}
