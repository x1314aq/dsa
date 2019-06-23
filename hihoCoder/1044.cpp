/**
 * hihoCoder 1044  状态压缩
 * DP
 */

#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int value[1005];
int best[1005][1024];

int n, m, q;

int count(int n) {
    int res = 0;
    while(n) {
        res += n & 1;
        n >>= 1;
    }
    return res;
}

int main() {
    cin >> n >> m >> q;
    for(int i = 1; i <= n; i++)
        cin >> value[i];
    int limit = 1 << m;
    int c = 1 << (m - 1);

    for(int i = 1; i <= n; i++) {
        for(int j = 0; j < limit; j++) {
            if(count(j) > q) continue;
            if(j & 1)
                best[i][j] = max(best[i - 1][j >> 1], best[i - 1][(j >> 1) + c]) + value[i];
            else
                best[i][j] = max(best[i - 1][j >> 1], best[i - 1][(j >> 1) + c]);
        }
    }

    int ans = 0;
    for(int i = 0; i < limit; i++)
        if(best[n][i] > ans) ans = best[n][i];
    cout << ans << endl;
    return 0;
}
