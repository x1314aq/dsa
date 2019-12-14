//
// 1042 数字0-9的数量
//

#include <bits/stdc++.h>

using namespace std;
using ull = unsigned long long;

ull dp[20][20];
int digits[20];
int cur;

ull dfs(int pos, ull cnt, int limit) {
    if (pos == 0)
        return cnt;
    if (!limit && dp[pos][cnt])
        return dp[pos][cnt];

    int up = limit ? digits[pos] : 9;
    ull ans = 0;
    for (int i = 0; i <= up; i++) {
        if (i == cur)
            ans += dfs(pos - 1, cnt + 1, limit && i == up);
        else
            ans += dfs(pos - 1, cnt, limit && i == up);
    }

    if (!limit)
        dp[pos][cnt] = ans;
    return ans;
}

ull dfs0(int pos, ull cnt, int lead, int limit) {
    if (pos == 0)
        return cnt;
    if (!limit && !lead && dp[pos][cnt])
        return dp[pos][cnt];

    int up = limit ? digits[pos] : 9;
    ull ans = 0;
    for (int i = 0; i <= up; i++) {
        if (i == 0) {
            if (lead)
                ans += dfs0(pos - 1, cnt, 1, 0);
            else
                ans += dfs0(pos - 1, cnt + 1, 0, limit && i == up);
        }
        else {
            ans += dfs0(pos - 1, cnt, 0, limit && i == up);
        }
    }

    if (!limit && !lead)
        dp[pos][cnt] = ans;
    return ans;
}

ull solve(ull n) {
    int pos = 0;

    while (n) {
        digits[++pos] = n % 10;
        n /= 10;
    }

    memset(dp, 0, sizeof(dp));
    return cur ? dfs(pos, 0, 1) : dfs0(pos, 0, 1, 1);
}

int main() {
    ull a, b;

    cin >> a >> b;
    for (int i = 0; i <= 9; i++) {
        cur = i;
        cout << solve(b) - solve(a - 1) << endl;
    }
    return 0;
}
