#include <bits/stdc++.h>

using namespace std;

using pii = pair<int, int>;

int main() {
    int n, m;
    map<pii, int> q;

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    for (int p = 0; p < m; p++) {
        int op, i, j, k;
        cin >> op >> i >> j;
        auto u = make_pair(i, j);
        if (op == 1) {
            cin >> k;
            auto it = q.find(u);
            if (it != q.end()) {
                it->second = k;
            } else {
                q.insert(make_pair(u, k));
            }
        } else {
            cout << q[u] << '\n';
        }
    }
    cout << endl;
    return 0;
}