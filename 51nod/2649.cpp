//
// 2649 完全背包
//

#include <bits/stdc++.h>

using namespace std;

int C[105], W[105];
int n, v;
int dp[50005];

int main() {
    cin >> n >> v;
    for (int i = 0; i < n; i++)
        cin >> C[i] >> W[i];

    for (int i = 0; i < n; i++)
        for (int j = C[i]; j <= v; j++)
            dp[j] = max(dp[j], dp[j - C[i]] + W[i]);

    cout << dp[v] << endl;
    return 0;
}
