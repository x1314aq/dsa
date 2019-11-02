//
// 子序列的个数
//

#include <bits/stdc++.h>

using namespace std;
using ull = unsigned long long;

const int mod = 1e9 + 7;
int arr[100005];
ull dp[100005];
int lastone[100005];

int main() {
    int n;
    unordered_map<int, int> repeat;

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        auto it = repeat.find(arr[i]);
        if (it == repeat.end())
            repeat[arr[i]] = i;
        else {
            lastone[i] = it->second;
            it->second = i;
        }
    }

    dp[0] = 1;
    for (int i = 1; i <= n; i++) {
        dp[i] = dp[i - 1] * 2 % mod;
        if (lastone[i])
            dp[i] = (dp[i] - dp[lastone[i] - 1] + mod) % mod;
    }

    cout << dp[n] - 1 << endl;
    return 0;
}
