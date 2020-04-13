//
// 1091 合唱队形
//

#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    int h[105] = {0};
    int dp[2][105] = {0};
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> h[i];

    for (int i = 1; i <= n; i++)
        for (int j = 0; j < i; j++)
            if (h[i] > h[j])
                dp[0][i] = max(dp[0][i], dp[0][j] + 1);

    for (int i = n; i > 0; i--)
        for (int j = n + 1; j > i; j--)
            if (h[i] > h[j])
                dp[1][i] = max(dp[1][i], dp[1][j] + 1);

    int ans = 0;
    for (int i = 1; i <= n; i++)
        ans = max(ans, dp[0][i] + dp[1][i] - 1);
    cout << n - ans<< endl;
    return 0;
}
