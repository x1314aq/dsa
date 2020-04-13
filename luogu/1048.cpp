//
// 1048 采药
//

#include <bits/stdc++.h>

using namespace std;
int T, M;
int t[1005], v[1005];
int dp[1005];

int main() {
    ios::sync_with_stdio(false);
    cin >> T >> M;
    for (int i = 1; i <= M; i++)
        cin >> t[i] >> v[i];

    for (int i = 1; i <= M; i++)
        for (int j = T; j >= t[i]; j--)
            dp[j] = max(dp[j], dp[j - t[i]] + v[i]);

    cout << dp[T] << endl;
    return 0;
}
