#include <bits/stdc++.h>

using namespace std;
using ll = long long int;

const int mod = 1e9 + 7;

int n;
int a[5005];

int main() {
    int maxn = 0;
    int ans = 0;
    int ch = 0;
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        int t;
        cin >> t;
        a[t]++;
        maxn = max(maxn, t);
    }
    for (int i = 1; i <= maxn; ++i) {
        for (int j = 0; j * 2 <= i; ++j) {
            if (i == 2 * j) ch = a[j] * (a[j] - 1) / 2;
            else ch = a[j] * a[i - j];
            ans = (ans + ch * a[i] * (a[i] - 1) / 2) % mod;
        }
    }
    cout << ans % mod << endl;
    return 0;
}