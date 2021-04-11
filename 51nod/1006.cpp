//
// 1006 最长公共子序列(LCS)
//

#include <bits/stdc++.h>

using namespace std;

int dp[1005][1005];
int c[1005][1005];

void show(string &a, int i, int j) {
    if (i == 0 || j == 0)
        return;
    if (c[i][j] == 0) {
        show(a, i - 1, j - 1);
        cout << a[i - 1];
    } else if (c[i][j] == 1)
        show(a, i - 1, j);
    else
        show(a, i, j - 1);
}

int main() {
    string a, b;
    cin >> a >> b;
    int len_a = a.length();
    int len_b = b.length();

    for (int i = 1; i <= len_a; i++) {
        for (int j = 1; j <= len_b; j++) {
            if (a[i - 1] == b[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
                c[i][j] = 0;
            } else if (dp[i - 1][j] >= dp[i][j - 1]) {
                dp[i][j] = dp[i - 1][j];
                c[i][j] = 1;
            } else {
                dp[i][j] = dp[i][j - 1];
                c[i][j] = -1;
            }
        }
    }

    show(a, len_a, len_b);
    cout << endl;

    return 0;
}
