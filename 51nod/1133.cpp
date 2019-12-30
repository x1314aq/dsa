//
// 1133 不重叠的线段
//

#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pll = pair<ll, ll>;

bool cmp(const pll &a, const pll &b) {
    return a.first < b.first ? true : (a.first == b.first ? a.second < b.second : false);
}

int main() {
    int n;
    vector<pll> arr;

    cin >> n;
    for (int i = 0; i < n; i++) {
        ll a, b;
        cin >> a >> b;
        arr.push_back(make_pair(a, b));
    }

    sort(arr.begin(), arr.end(), cmp);
    int ans = 1;
    int emin = arr[0].second;
    for (int i = 1; i < n; i++) {
        int s = arr[i].first;
        int e = arr[i].second;
        if (s < emin)
            emin = min(emin, e);
        else {
            ans++;
            emin = e;
        }
    }

    cout << ans << endl;
    return 0;
}
