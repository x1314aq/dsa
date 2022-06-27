#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int main() {
    ll ans = 0, num = 0;
    int n;
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    while (cin >> n) {
        ans += n;
        num++;
    }
    cout << ans * (1 << (num - 1)) << endl;
    return 0;
}
