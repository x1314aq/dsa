//
// 1212 无向图最小生成树
//

#include <bits/stdc++.h>

using namespace std;

struct edge {
    int from, to;
    int weight;
};

edge es[50005];
int sup[50005];

int find(int x) {
    return sup[x] = sup[x] == x ? x : find(sup[x]);
}

void join(int x, int y) {
    sup[x] = y;
}

bool cmp(const edge &a, const edge &b) {
    return a.weight < b.weight;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    for (int i = 1; i <= m; i++)
        scanf("%d %d %d", &es[i].from, &es[i].to, &es[i].weight);
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
            ans += es[i].weight;
        }
    }
    printf("%d\n", ans);
    return 0;
}
