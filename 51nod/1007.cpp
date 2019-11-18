//
// 1007 正整数分组
//

#include <bits/stdc++.h>

using namespace std;

int a[105];
int dp[5005];

int main() {
    int n, sum = 0;

    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        sum += a[i];
    }

    for(int i = 1; i <= n; i++)
        for(int j = sum / 2; j >= a[i]; j--)
            dp[j] = max(dp[j], dp[j - a[i]] + a[i]);

    cout << abs(sum - 2 * dp[sum / 2]) << endl;
    return 0;
}
