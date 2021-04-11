//
// 1002 数塔取数问题
//

#include <bits/stdc++.h>

using namespace std;

int dp[505];

int main() {
    int n, ans = 0;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        int old1, old2;
        old1 = dp[0];
        for (int j = 1; j <= i; j++) {
            int tmp;
            scanf("%d", &tmp);
            old2 = dp[j];
            dp[j] = max(old1, old2) + tmp;
            ans = max(ans, dp[j]);
            old1 = old2;
        }
    }

    printf("%d\n", ans);
    return 0;
}
