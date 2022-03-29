#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

static bool cmp(pii &a, pii &b) {
    return a.first < b.first;
}

static int bsearch(vector<pii> &v, int x) {
    int l = 0, r = v.size();
    int u;

    while (l < r) {
        int m = l + (r - l) / 2;
        u = v[m].first;
        if (u == x) {
            return v[m].second;
        } else if (u < x) {
            l = m + 1;
        } else {
            r = m;
        }
    }
    return 0;
}

int main() {
    int n;
    vector<pii> v;
    v.reserve(100005);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int u;
        cin >> u;
        v.push_back(make_pair(u, i));
    }
    sort(v.begin(), v.end(), cmp);
    cin >> n;
    for (int i = 0; i < n; i++) {
        int u;
        cin >> u;
        cout << bsearch(v, u) << '\n';
    }
    cout.flush();
    return 0;
}