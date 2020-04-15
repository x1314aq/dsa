//
// 1536 村村通
//

#include <bits/stdc++.h>

using namespace std;

int sup[1005];

int find(int x) {
    return sup[x] = (x == sup[x] ? x : find(sup[x]));
}

int main() {
    int n,m;
    ios::sync_with_stdio(false);
    cin >> n;
    while (n != 0) {
        int ans = 0;
        cin >> m;
        for (int i = 1; i <= n; i++)
            sup[i] = i;
        for (int i = 1; i <= m; i++) {
            int a, b;
            cin >> a >> b;
            int fa = find(a);
            int fb = find(b);
            if (fa != fb)
                sup[fa] = fb;
        }
        for (int i = 1; i <= n; i++) {
            if (sup[i] == i)
                ans++;
        }
        cout << ans - 1 << endl;
        cin >> n;
    }
    return 0;
}
