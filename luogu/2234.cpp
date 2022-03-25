#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int main() {
    int n;
    int ans = 0;
    set<int> s;

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a;

        if (!s.empty()) {
            auto it = s.lower_bound(a);
            if (it != s.end()) {
                b = *it - a;
                if (it != s.begin()) {
                    --it;
                    b = min(b, abs(*it - a));
                }
            } else {
                b = a - *s.rbegin();
            }
        } else {
            b = a;
        }
        ans += b;
        if (b != 0) {
            s.insert(a);
        }
    }
    cout << ans << endl;
    return 0;
}