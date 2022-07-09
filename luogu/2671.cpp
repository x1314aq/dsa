#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int number[100005];
int color[100005];
int sum[100005][2], nt[100005][2];

const int mod = 10007;

int main() {
    int n, m;
    ll ans = 0;
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> number[i];
    }
    for (int i = 1; i <= n; i++) {
        int c;
        cin >> c;
        color[i] = c;
        nt[c][i % 2]++;
        sum[c][i % 2] = (sum[c][i % 2] + number[i]) % mod;
    }
    for (int i = 1; i <= n; i++) {
        int c = color[i];
        ans = (ans + i % mod * ((sum[c][i % 2] + (nt[c][i % 2] - 2) % mod * number[i] + mod) % mod)) % mod;
    }
    cout << ans << endl;
    return 0;
}
