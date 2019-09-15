/**
 * hihoCoder 1037  数字三角形
 * DP
 */


#include <bits/stdc++.h>
using namespace std;

int bonus[105][105];
int ans[105][105];

int main() {
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= i; j++)
            cin >> bonus[i][j];

    ans[1][1] = bonus[1][1];
    for(int i = 2; i <= n; i++)
        for(int j = 1; j <= i; j++)
            ans[i][j] = max(ans[i - 1][j], ans[i - 1][j - 1]) + bonus[i][j];

    int res = -1;
    for(int i = 1; i <= n; i++)
        if(ans[n][i] > res) res = ans[n][i];
    cout <<  res << endl;
    return 0;
}
