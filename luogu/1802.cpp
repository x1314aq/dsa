//
// 1802 五倍经验日
//

#include <bits/stdc++.h>

using namespace std;
int n, x;
long long lose[1005], win[1005], use[1005];
long long dp[1005];

int main() {
    ios::sync_with_stdio(false);
    cin >> n >> x;
    for (int i = 1; i <= n; i++)
        cin >> lose[i] >> win[i] >> use[i];

    for (int i = 1; i <= n; i++) {
        for (int j = x; j >= use[i]; j--)
            dp[j] = max(dp[j] + lose[i], dp[j - use[i]] + win[i]);
        for (int j = use[i] - 1; j >= 0; j--)
            dp[j] += lose[i];
    }

    cout << 5 * dp[x] << endl;
    return 0;
}
