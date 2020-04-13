//
// 1507 NASA的食物计划
//

#include <bits/stdc++.h>

using namespace std;

int main() {
    int V, M, N;
    int v[55], m[55], c[55];
    int dp[405][405];

    ios::sync_with_stdio(false);
    cin >> V >> M >> N;
    for (int i = 1; i <= N; i++)
        cin >> v[i] >> m[i] >> c[i];

    for (int i = 1; i <= N; i++)
        for (int j = V; j >= v[i]; j--)
            for (int k = M; k >= m[i]; k--)
                dp[j][k] = max(dp[j][k], dp[j - v[i]][k - m[i]] + c[i]);

    cout << dp[V][M] << endl;
    return 0;
}
