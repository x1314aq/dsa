//
// 1757 通天之分组背包
//

#include <bits/stdc++.h>

using namespace std;
int M, N;
int w[1005], v[1005], cc[105][25], cn[105], up;
int dp[1005];

int main() {
    ios::sync_with_stdio(false);
    cin >> M >> N;
    for (int i = 1; i <= N; i++) {
        int c;
        cin >> w[i] >> v[i] >> c;
        up = max(c, up);
        cn[c]++;
        cc[c][cn[c]] = i;
    }

    for (int i = 1; i <= up; i++)
        for (int j = M; j >= 0; j--)
            for (int k = 1; k <= cn[i]; k++)
                if (j >= w[cc[i][k]])
                    dp[j] = max(dp[j], dp[j - w[cc[i][k]]] + v[cc[i][k]]);

    cout << dp[M] << endl;
    return 0;
}
