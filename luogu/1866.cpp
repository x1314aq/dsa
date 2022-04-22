#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int main() {
    int n;
    vector<int> v;
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 0; i < n; i++) {
        int u;
        cin >> u;
        v.push_back(u);
    }
    sort(v.begin(), v.end());
    ll ans = 1;
    const int mod = 1000000007;
    for (int i = 0; i < v.size(); i++) {
        ans = (ans * (v[i] - i)) % mod;
    }
    cout << ans << endl;
    return 0;
}