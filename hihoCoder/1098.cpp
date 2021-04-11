/**
 * hihoCoder 1098  最小生成树一Kruscal算法
 * Kruscal + 并查集
 */

#include <bits/stdc++.h>
using namespace std;

struct edge {
    int from, to;
    int cost;
};

edge es[1000005];
int sup[100005];

int find(int x) {
    int r = x;
    while (r != sup[r])
        r = sup[r];

    int i = x, j;
    while (i != r) {
        j = sup[i];
        sup[i] = r;
        i = j;
    }
    return r;
}

static inline void join(int x, int y) {
    sup[x] = y;
}

bool cmp(edge &a, edge &b) {
    return a.cost < b.cost;
}

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
        scanf("%d %d %d", &es[i].from, &es[i].to, &es[i].cost);
    sort(es + 1, es + m + 1, cmp);
    for (int i = 1; i <= n; i++)
        sup[i] = i;

    int ans = 0;
    for (int i = 1; i <= m; i++) {
        int from = es[i].from;
        int to = es[i].to;
        int fx = find(from);
        int fy = find(to);
        if (fx != fy) {
            join(fx, fy);
            ans += es[i].cost;
        }
    }

    printf("%d\n", ans);
    return 0;
}
