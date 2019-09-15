/**
 * hihoCoder 1239   Fibonacci
 * DP
 */


#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int f[30];
ll dp[30];
ll ans;
const ll mod = 1000000007;
map<int, int> m;

int main() {
    f[0] = f[1] = 1;
    for(int i = 2; i < 30; i++)
        f[i] = f[i - 1] + f[i - 2];

    for(int i = 1; i < 30; i++)
        m[f[i]] = i;

    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        int tmp;
        scanf("%d", &tmp);
        if(tmp == 1) {
            if(!dp[0]) {
                dp[0]++;
                ans++;
                dp[0] %= mod;
                ans %= mod;
            }
            else {
                ans += dp[0];
                dp[1] += dp[0];
                dp[0]++;
                ans++;
                dp[0] %= mod;
                dp[1] %= mod;
                ans %= mod;
            }
        }
        else if(m[tmp]) {
            int x = m[tmp];
            dp[x] += dp[x - 1];
            ans += dp[x - 1];
            dp[x] %= mod;
            ans %= mod;
        }
    }

    printf("%lld\n", ans);
    return 0;
}
