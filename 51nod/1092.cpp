//
// 1092 回文字符串
//

#include <bits/stdc++.h>

using namespace std;

int lcs(char *str, size_t len) {
    int dp[1005][1005] = {0};

    for (int i = 0; i < len; i++)
        for (int j = 0; j < len; j++)
            if (str[i] == str[len - 1 - j])
                dp[i + 1][j + 1] = dp[i][j] + 1;
            else
                dp[i + 1][j + 1] = max(dp[i][j + 1], dp[i + 1][j]);
    return dp[len][len];
}

int main() {
    char str[1005];
    size_t len;

    cin >> str;
    len = strlen(str);

    cout << len - lcs(str, len) << endl;
    return 0;
}
