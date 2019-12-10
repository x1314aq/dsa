//
// 2517 最少01翻转次数
//

#include <bits/stdc++.h>

using namespace std;

char a[20005];
int sum0[20005], sum1[20005];

int main() {
    int n;

    scanf("%d\n %s", &n, a + 1);
    for (int i = 1; i <= n; i++)
        sum1[i] = sum1[i - 1] + (a[i] - '0');
    for (int i = n; i >= 1; i--)
        sum0[i] = sum0[i + 1] + ('1' - a[i]);

    int ans = n;
    for (int i = 0; i <= n; i++)
        ans = min(ans, sum1[i] + sum0[i + 1]);

    printf("%d\n", ans);
    return 0;
}
