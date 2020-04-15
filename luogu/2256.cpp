//
// 2256 一中校运会之百米跑
//

#include <bits/stdc++.h>

using namespace std;

int sup[20005];

int find(int x) {
    return sup[x] = (x == sup[x] ? x : find(sup[x]));
}

int main() {
    int n, m, q;
    unordered_map<string, int> dict;
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        dict[s] = i;
        sup[i] = i;
    }
    for (int i = 0; i < m; i++) {
        string a, b;
        cin >> a >> b;
        int fa = find(dict[a]);
        int fb = find(dict[b]);
        if (fa != fb)
            sup[fa] = fb;
    }
    cin >> q;
    for (int i = 0; i < q; i++) {
        string a, b;
        cin >> a >> b;
        if (find(dict[a]) == find(dict[b]))
            cout << "Yes." << endl;
        else
            cout << "No." << endl;
    }
    return 0;
}
