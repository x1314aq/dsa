#include <bits/stdc++.h>

using namespace std;
int n, k;
int a[25];

void dfs(int m, int startx) {
    if (m == k) {
        for (int i = 0; i < k; i++) {
            printf("%3d", a[i]);
        }
        putchar('\n');
        return;
    }
    for (int i = startx + 1; i <= n; i++) {
        a[m] = i;
        dfs(m + 1, i);
    }
}

int main() {
    scanf("%d%d", &n, &k);
    dfs(0, 0);
    return 0;
}
