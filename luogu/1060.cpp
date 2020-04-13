//
// 1060 开心的金明
//

#include <bits/stdc++.h>

using namespace std;
int N, M;
int v[30], w[30];
int dp[30005];

int main() {
    ios::sync_with_stdio(false);
    cin >> N >> M;
    for (int i = 1; i <= M; i++)
        cin >> v[i] >> w[i];

    for (int i = 1; i <= M; i++)
        for (int j = N; j >= v[i]; j--)
            dp[j] = max(dp[j], dp[j - v[i]] + v[i] * w[i]);

    cout << dp[N] << endl;
    return 0;
}
