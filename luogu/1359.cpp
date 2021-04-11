//
// 1359 租用游艇
//

#include <bits/stdc++.h>

using namespace std;
int m[205][205];
int dp[205];

int main() {
    int n;

    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i < n; i++)
        for (int j = i + 1; j <= n; j++)
            cin >> m[i][j];

    for (int i = 2; i <= n; i++) {
        int tmp = 10000000;
        for (int j = 1; j < i; j++) {
            tmp = min(tmp, dp[j] + m[j][i]);
        }
        dp[i] = tmp;
    }
    cout << dp[n] << endl;
    return 0;
}
