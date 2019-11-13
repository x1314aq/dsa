//
// 1051 最大子矩阵和
//

#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int matrix[505][505];
ll arr[505];

ll fn(int n) {
    ll ans, tmp;

    ans = tmp = arr[1];
    for (int i = 2; i <= n; i++) {
        tmp = max(arr[i], arr[i] + tmp);
        ans = max(ans, tmp);
    }
    return ans;
}

int main() {
    int n, m;

    scanf("%d %d", &m, &n);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            scanf("%d", &matrix[i][j]);

    ll ans = -1;
    for (int i = 1; i <= m; i++) {
        for (int j = i; j <= m; j++) {
            for (int k = 1; k <= n; k++)
                arr[k] = (i == j ? matrix[k][i] : arr[k] + matrix[k][j]);

            ans = max(ans, fn(n));
        }
    }

    ans = ans < 0 ? 0 : ans;
    printf("%lld\n", ans);
    return 0;
}
