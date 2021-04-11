//
// 1195 口袋的天空
//

#include <bits/stdc++.h>

using namespace std;
using ull = unsigned long long;

int sup[1005];

int find(int x) {
    return sup[x] = (x == sup[x] ? x : find(sup[x]));
}

struct edge {
    int from;
    int to;
    int weight;
} g[10005];

bool cmp(const edge &a, const edge &b) {
    return a.weight < b.weight;
}

int main() {
    int n, m, k;
    ios::sync_with_stdio(false);
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++)
        sup[i] = i;
    for (int i = 0; i < m; i++)
        cin >> g[i].from >> g[i].to >> g[i].weight;
    sort(g, g + m, cmp);
    ull ans = 0;
    for (int i = 0; i < m; i++) {
        if (n == k)
            break;
        int fu = find(g[i].from);
        int fv = find(g[i].to);
        if (fu != fv) {
            sup[fu] = fv;
            n--;
            ans += g[i].weight;
        }
    }
    if (n != k)
        cout << "No Answer" << endl;
    else
        cout << ans << endl;
    return 0;
}
