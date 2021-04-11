//
// 1111 修复公路
//

#include <bits/stdc++.h>

using namespace std;

int sup[1005];

int find(int x) {
    return sup[x] = (x == sup[x] ? x : find(sup[x]));
}

struct node {
    int x, y, t;
    bool operator<(const node &a) const { return t < a.t; }
} v[100005];

int main() {
    int n, m;
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        sup[i] = i;
    for (int i = 0; i < m; i++)
        cin >> v[i].x >> v[i].y >> v[i].t;
    sort(v, v + m);

    int ans = 0;
    for (int i = 0; i < m; i++) {
        int fx = find(v[i].x);
        int fy = find(v[i].y);
        if (fx != fy) {
            sup[fx] = fy;
            n--;
            ans = v[i].t;
        }
    }
    if (n != 1)
        ans = -1;
    cout << ans << endl;
    return 0;
}
