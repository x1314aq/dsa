//
// 3370 字符串hash
//

#include <bits/stdc++.h>

using namespace std;
using ull = unsigned long long;
using pll = pair<ull, ull>;

pll a[10005];
const int base = 131;
const int mod1 = 19260817;
const int mod2 = 19660813;

ull hash1(const string &s) {
    ull ans = 0;
    for (auto c : s)
        ans = (ans * base + (ull)c) % mod1;
    return ans;
}

ull hash2(const string &s) {
    ull ans = 0;
    for (auto c : s)
        ans = (ans * base + (ull)c) % mod2;
    return ans;
}

int main() {
    int n;
    ios::sync_with_stdio(false);

    cin >> n;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        a[i].first = hash1(s);
        a[i].second = hash2(s);
    }
    sort(a, a + n);
    int ans = 1;
    for (int i = 1; i < n; i++) {
        if (a[i].first != a[i - 1].first || a[i].second != a[i - 1].second)
            ans++;
    }
    cout << ans << endl;
}
