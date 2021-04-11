/**
 * hihoCoder 1977  小Hi与魔法
 */

#include <bits/stdc++.h>
using namespace std;
int hs[1000001];

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int tmp;
        scanf("%d", &tmp);
        hs[tmp]++;
    }

    int ans = 0;
    for (int i = 1; i <= 1000000; i++) {
        if (hs[i] == 0)
            break;
        ans += hs[i];
    }

    printf("%d\n", ans);
    return 0;
}
