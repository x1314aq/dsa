//
// 更难的矩阵取数问题
//

#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int matrix[205][205];
ll dp[205][205];

int main() {
    int n, m;

    cin >> m >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> matrix[i][j];

    dp[1][1] = matrix[1][1];
    for (int s = 2; s < n + m; s++) {
        for (int x1 = n; x1 >= 1; x1--) {
            int y1 = s + 1 - x1;
            for (int x2 = n; x2 >= 1; x2--) {
                int y2 = s + 1 - x2;
                ll tmp = dp[x1 - 1][x2 - 1];
                
                tmp = max(tmp, dp[x1 - 1][x2]);
                tmp = max(tmp, dp[x1][x2 - 1]);
                tmp = max(tmp, dp[x1][x2]);
                dp[x1][x2] = tmp + matrix[x1][y1];
                if (x1 != x2)
                    dp[x1][x2] += matrix[x2][y2];
            }
        }
    }

    cout << dp[n][n] << endl;
    return 0;
}
