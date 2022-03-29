#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int main() {
    int n;
    multiset<int> s;
    s.insert(-0x7fffffff);
    s.insert(0x7fffffff);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 0; i < n; i++) {
        int op, u, k;
        multiset<int>::iterator it;
        cin >> op >> u;

        switch (op) {
        case 1:
            k = 0;
            it = s.lower_bound(u);
            for (auto tmp = s.begin(); tmp != it; ++tmp, ++k) {
            }
            cout << k << '\n';
            break;
        case 2:
            for (k = -1, it = s.begin(); it != s.end(); ++it) {
                if (++k == u) {
                    cout << *it << '\n';
                    break;
                }
            }
            break;
        case 3:
            it = s.lower_bound(u);
            --it;
            cout << *it << '\n';
            break;
        case 4:
            it = s.upper_bound(u);
            cout << *it << '\n';
            break;
        case 5:
            s.insert(u);
            break;
        }
    }
    cout.flush();
    return 0;
}