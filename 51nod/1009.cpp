//
// 1009 数字1的数量
//

#include <bits/stdc++.h>

using namespace std;

int dp[10][11];
int digits[11];

int dfs(int pos, int cnt, int limit) {
    if (pos == 0)
        return cnt;

    if (!limit && dp[pos][cnt])
        return dp[pos][cnt];

    int up = limit ? digits[pos] : 9;
    int ans = 0;
    for (int i = 0; i <= up; i++) {
        if (i == 1)
            ans += dfs(pos - 1, cnt + 1, limit && i == up);
        else
            ans += dfs(pos - 1, cnt, limit && i == up);
    }

    if (!limit)
        dp[pos][cnt] = ans;
    return ans;
}

int solve(int n) {
    int pos = 0;
    while (n) {
        digits[++pos] = n % 10;
        n /= 10;
    }
    return dfs(pos, 0, 1);
}

int main() {
    int n;

    cin >> n;
    cout << solve(n) << endl;
    return 0;
}
