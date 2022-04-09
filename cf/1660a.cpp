#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int main() {
    int t, a, b;
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    while (t--) {
        cin >> a >> b;
        if (a == 0) {
            cout << 1 << '\n';
        } else {
            cout << 2 * (b + 1) + (a - 1) << '\n';
        }
    }
    cout.flush();
    return 0;
}