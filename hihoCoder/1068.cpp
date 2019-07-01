/**
 * hihoCoder 1068  RMQ-ST算法
 */

#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cmath>

using namespace std;

int calc[1000005][25];
int res[1000005];

int main() {
    int n, q;

    memset(calc, 0x0a, sizeof(calc));
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
        scanf("%d", &calc[i][0]);

    int b = int(log((double)n)/log(2.0));
    for(int j = 1; j <= b; j++)
        for(int i = 1; i + (1 << (j - 1)) - 1 <= n; i++)
            calc[i][j] = min(calc[i][j - 1], calc[i + (1 << (j - 1))][j - 1]);

    scanf("%d", &q);
    for(int i = 1; i <= q; i++) {
        int l, r;
        scanf("%d %d", &l, &r);
        int p = int(log((double)(r-l+1))/log(2.0));
        res[i] = min(calc[l][p], calc[r - (1 << p) + 1][p]);
    }

    for(int i = 1; i <= q; i++)
        printf("%d\n", res[i]);
    return 0;
}
