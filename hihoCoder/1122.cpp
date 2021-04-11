/**
 * hihoCoder 1121 二分图二·二分图最大匹配之匈牙利算法
 * 匈牙利算法
 */

#include <bits/stdc++.h>
using namespace std;

vector<int> vs[1005];
int match[1005];
int vis[1005];

bool find_path(int u) {
    int sz = vs[u].size();
    for (int i = 0; i < sz; i++) {
        int v = vs[u][i];
        if (vis[v])
            continue;
        vis[v] = 1;
        if (match[v] == 0 || find_path(match[v])) {
            match[u] = v;
            match[v] = u;
            return true;
        }
    }
    return false;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        vs[u].push_back(v);
        vs[v].push_back(u);
    }

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (match[i])
            continue;
        memset(vis, 0, 1005 * sizeof(int));
        vis[i] = 1;
        if (find_path(i))
            ans++;
    }

    printf("%d\n", ans);
    return 0;
}
