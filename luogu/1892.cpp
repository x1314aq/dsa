//
// 1892 [BOI2003]团伙
//

#include <bits/stdc++.h>

using namespace std;

int sup[1005];
vector<int> v[1005];

int find(int x) {
    return sup[x] = (x == sup[x] ? x : find(sup[x]));
}

void join(int a, int b) {
    int fa = find(a);
    int fb = find(b);
    if (fa != fb)
        sup[fa] = fb;
}

int main() {
    int n, m;
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        sup[i] = i;
    for (int i = 0; i < m; i++) {
        char c;
        int a, b;
        cin >> c >> a >> b;
        if (c == 'F')
            join(a, b);
        else {
            v[a].push_back(b);
            v[b].push_back(a);
        }
    }

    for (int i = 1; i <= n; i++) {
        if (v[i].size()) {
            for (int p = 0; p < v[i].size(); p++)
                for (int q = p + 1; q < v[i].size(); q++)
                    join(v[i][p], v[i][q]);
        }
    }

    int ans = 0;
    for (int i = 1; i <= n; i++)
        if (sup[i] == i)
            ans++;
    cout << ans << endl;
    return 0;
}
