//
// 1521 一维战舰
//

#include <bits/stdc++.h>

using namespace std;

int n, k, a;
int m;
int b[200005];
set<int> c;
int vis[200005];

int main() {
    cin >> n >> k >> a >> m;
    for (int i = 1; i <= m; i++)
        cin >> b[i];

    int d = (n + 1) / (a + 1);
    c.insert(0);
    c.insert(n + 1);

    for (int i = 1; i <= m; i++) {
        auto p = c.insert(b[i]);
        if (!p.second)
            continue;

        auto it1 = p.first, it2 = p.first;
        int u = *--it1;
        int v = *++it2;
        d -= ((v - u) / (a + 1) - (b[i] - u) / (a + 1) - (v - b[i]) / (a + 1));
        if (d < k) {
            cout << i << endl;
            return 0;
        }
    }

    cout << -1 << endl;
    return 0;
}
