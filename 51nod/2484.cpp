//
// 2484 小b和排序
//

#include <bits/stdc++.h>

using namespace std;

int arr[2][2005];
int dp[2][2005];

int main() {
    int n;

    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> arr[0][i];
    for (int i = 1; i <= n; i++)
        cin >> arr[1][i];

    memset(dp, 0x3f, sizeof(dp));
    dp[0][1] = 0, dp[1][1] = 1;
    for (int i = 2; i <= n; i++) {
        if (arr[0][i] > arr[0][i - 1] && arr[1][i] > arr[1][i - 1]) {
            dp[0][i] = min(dp[0][i], dp[0][i - 1]);
            dp[1][i] = min(dp[1][i], dp[1][i - 1] + 1);
        }
        if (arr[0][i] > arr[1][i - 1] && arr[1][i] > arr[0][i - 1]) {
            dp[0][i] = min(dp[0][i], dp[1][i - 1]);
            dp[1][i] = min(dp[1][i], dp[0][i - 1] + 1);
        }
    }

    cout << min(dp[0][n], dp[1][n]) << endl;
    return 0;
}
