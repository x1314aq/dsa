//
// 3383 线性筛素数
//

// 这题用cin/cout会超时，必须用scanf/printf

#include <bits/stdc++.h>

using namespace std;

bool a[100000005];
int p[100000005];
int cnt;

void prime(int n) {
    memset(a, 1, sizeof(a));
    for (int i = 2; i <= n; i++) {
        if (a[i])
            p[++cnt] = i;
        for (int j = 1; j <= cnt && i * p[j] <= n; j++) {
            a[i * p[j]] = 0;
            if (i % p[j] == 0)
                break;
        }
    }
}

int main() {
    int n, q;
    scanf("%d %d", &n, &q);
    prime(n);
    while (q--) {
        int t;
        scanf("%d", &t);
        printf("%d\n", p[t]);
    }
    return 0;
}
