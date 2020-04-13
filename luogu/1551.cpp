//
// 1551 亲戚
//

#include <bits/stdc++.h>

using namespace std;

int sup[5005];

int find(int x) {
    return sup[x] = (x == sup[x] ? x : find(sup[x]));
}

int main() {
    int n, m, p;
    ios::sync_with_stdio(false);
    cin >> n >> m >> p;
    for (int i = 1; i <= n; i++)
        sup[i] = i;
    for (int i = 1; i <= m; i++) {
        int a, b;
        cin >> a >> b;
        sup[find(a)] = find(b);
    }
    for (int i = 1; i <= p; i++) {
        int a, b;
        cin >> a >> b;
        if (find(a) == find(b))
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    return 0;
}
