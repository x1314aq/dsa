#include <bits/stdc++.h>

using namespace std;
using ll = long long int;

int n, x;
ll a[100005];
ll b[100005];

int main() {
    ll ans = 0;
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> x;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        b[i] = a[i] + a[i - 1];
    }

    for (int i = 1; i <= n; i++) {
        if (b[i] > x) {
            int c = b[i] - x;
            ans += c;
            b[i + 1] -= c;
        }
    }
    cout << ans << endl;
    return 0;
}