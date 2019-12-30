//
// 2599 最近公共祖先(LCA)
//

#include <bits/stdc++.h>

using namespace std;

int sup[1005];

int query(int a, int b) {
    set<int> tmp;

    do {
        tmp.insert(a);
        a = sup[a];
    } while (a);

    do {
        auto ans = lower_bound(tmp.begin(), tmp.end(), b);
        if (*ans == b)
            return b;
        b = sup[b];
    } while (b);
    return 0;
}

int main() {
    int n, m;

    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        sup[v] = u;
    }

    cin >> m;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        cout << query(a, b) << endl;
    }
    return 0;
}
