//
// 1118 机器人走方格
//

#include <bits/stdc++.h>

using namespace std;
using  ull = unsigned long long;
const ull mod = 1e9 + 7;

ull maze[1005][1005];

int main() {
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        maze[i][1] = 1;
    for(int i = 1; i <= m; i++)
        maze[1][i] = 1;

    for(int i = 2; i <= n; i++)
        for(int j = 2; j <= m; j++)
            maze[i][j] = (maze[i][j - 1] + maze[i - 1][j]) % mod;
    cout << maze[n][m] << endl;
    return 0;
}
