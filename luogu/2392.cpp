#include <bits/stdc++.h>

using namespace std;
using ll = long long int;

int main() {
    int s[4];
    int a[25];
    int dp[2505];
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> s[0] >> s[1] >> s[2] >> s[3];
    int ans = 0;
    int sum = 0;
    for (int i = 0; i < 4; ++i) {
        memset(dp, 0, sizeof(dp));
        sum = 0;
        for (int j = 0; j < s[i]; ++j) {
            cin >> a[j];
            sum += a[j];
        }
        for (int j = 0; j < s[i]; ++j) {
            for (int k = sum / 2; k >= a[j]; --k) {
                dp[k] = max(dp[k], dp[k - a[j]] + a[j]);
            }
        }
        ans += sum - dp[sum / 2];
    }
    cout << ans << endl;

    return 0;
}