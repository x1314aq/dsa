//
// 1044 栈
//

#include <bits/stdc++.h>

using namespace std;

int m[20][20];

int dfs(int i, int j) {
    if (m[i][j])
        return m[i][j];
    if (i == 0)
        return 1;
    if (j > 0)
        m[i][j] += dfs(i, j - 1);
    m[i][j] += dfs(i - 1, j + 1);
    return m[i][j];
}

int main() {
    int n, ans;
    ios::sync_with_stdio(false);
    cin >> n;
    cout << dfs(n, 0) << endl;
    return 0;
}
