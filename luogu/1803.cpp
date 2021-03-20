#include <bits/stdc++.h>

using namespace std;
using pii = pair<int, int>;
using ll = long long int;

int n;
pii a[1000005];

bool cmp(const pii &q, const pii &w) {
    return q.second < w.second;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i].first >> a[i].second;
    }

    sort(a, a + n, cmp);
    int ans = 1;
    int end = a[0].second;
    for (int i = 1; i < n; i++) {
        if (a[i].first >= end) {
            ans++;
            end = a[i].second;
        }
    }
    cout << ans << endl;
    return 0;
}
