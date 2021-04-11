//
// 100521【模板】路径压缩
//

#include <bits/stdc++.h>

using namespace std;

int sup[1000005];

int find(int x) {
    return sup[x] = (sup[x] == x ? x : find(sup[x]));
}

int main() {
    int n, k, m;
    ios::sync_with_stdio(false);

    cin >> n >> k;
    for (int i = 1; i <= k; i++)
        sup[i] = i;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        int fa = find(a);
        int fb = find(b);
        if (fa != fb)
            sup[fb] = fa;
    }
    cin >> m;
    for (int i = 0; i < m; i++) {
        int c;
        cin >> c;
        if (c == 0) {
            int a, b;
            cin >> a >> b;
            if (find(a) == find(b))
                cout << "Yes" << endl;
            else
                cout << "No" << endl;
        } else {
            int a;
            cin >> a;
            cout << find(a) << endl;
        }
    }
    return 0;
}
