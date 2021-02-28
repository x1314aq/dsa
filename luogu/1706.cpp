#include <bits/stdc++.h>

using namespace std;

bool vis[15];
int a[15];
int n;

void dfs(int k) {
    if (k == n) {
        for (int i = 0; i < n; i++)
            printf("%5d", a[i]);
        putchar('\n');
        return;
    }
    for (int i = 1; i <= n; i++) {
        a[k] = i;
        if (!vis[i]) {
            vis[i] = true;
            dfs(k + 1);
            vis[i] = false;
        }
    }
}

int main() {
    scanf("%d", &n);
    dfs(0);
    return 0;
}
