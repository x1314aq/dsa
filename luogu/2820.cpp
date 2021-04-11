//
// 2820 局域网
//

#include <bits/stdc++.h>

using namespace std;

struct edge {
    int x, y, w;
    bool operator<(const edge &b) const { return w < b.w; }
} g[10005];

int sup[105];

int find(int x) {
    return sup[x] = (x == sup[x] ? x : find(sup[x]));
}

int main() {
    int n, k;
    ios::sync_with_stdio(false);
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        sup[i] = i;
    for (int i = 0; i < k; i++)
        cin >> g[i].x >> g[i].y >> g[i].w;
    sort(g, g + k);

    int cnt = 0;
    int ans = 0;
    for (int i = 0; i < k; i++) {
        int fx = find(g[i].x);
        int fy = find(g[i].y);
        if (fx != fy) {
            sup[fx] = fy;
            cnt++;
        } else
            ans += g[i].w;
        if (cnt == n - 1) {
            for (int j = i + 1; j < k; j++)
                ans += g[j].w;
            break;
        }
    }
    cout << ans << endl;
    return 0;
}
