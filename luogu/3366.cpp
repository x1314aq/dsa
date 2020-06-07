//
// 3366 最小生成树
//

#include <bits/stdc++.h>

using namespace std;

int sup[5005];

int find(int x) {
    return sup[x] = (x == sup[x] ? x : find(sup[x]));
}

struct edge {
    int from;
    int to;
    int weight;
} g[200005];

bool cmp(const edge &a, const edge &b) {
    return a.weight < b.weight;
}

int main() {
    int n, m;
    ios::sync_with_stdio(false);

    cin >> n >> m;
    for (int i = 0; i < m; i++)
        cin >> g[i].from >> g[i].to >> g[i].weight;
    for (int i = 1; i <= n; i++)
        sup[i] = i;
    sort(g, g + m, cmp);
    unsigned long long ans = 0;
    int cnt = 0;
    for (int i = 0; i < m; i++) {
        int fu = find(g[i].from);
        int fv = find(g[i].to);
        if (fu == fv) continue;
        ans += g[i].weight;
        sup[fu] = fv;
        cnt++;
        if (cnt == n - 1) break;
    }
    if (cnt == n - 1)
        cout << ans << endl;
    else cout << "orz" << endl;
    return 0;
}
