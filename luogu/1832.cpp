//
// 1832 A+B Problem（再升级）
//

#include <bits/stdc++.h>

using namespace std;

bool not_prime[1005];
void fn() {
    for (int i = 2; i <= 500; i++)
        if (!not_prime[i])
            for (int j = 2; j * i <= 1000; j++)
                not_prime[j * i] = true;
}

int main() {
    int n;
    long long dp[1005] = {0};
    ios::sync_with_stdio(false);
    fn();
    cin >> n;
    dp[0] = 1;
    for (int i = 2; i <= n; i++) {
        if (!not_prime[i]) {
            for (int j = i; j <= n; j++)
                dp[j] += dp[j - i];
        }
    }

    cout << dp[n] << endl;
    return 0;
}
