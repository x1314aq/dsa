#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int main() {
    int n;
    set<int> s;
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 0; i < n; i++) {
        int op, x;
        cin >> op >> x;
        if (op == 1) {
            auto it = s.find(x);
            if (it != s.end()) {
                cout << "Already Exist\n";
            } else {
                s.insert(x);
            }
        } else {
            if (s.empty()) {
                cout << "Empty\n";
            } else {
                auto it = s.lower_bound(x);
                if (it == s.end()) {
                    cout << *s.rbegin() << '\n';
                    s.erase(--it);
                } else if (it == s.begin()) {
                    cout << *it << '\n';
                    s.erase(it);
                } else {
                    auto tmp = it--;
                    int u = *it;
                    int v = *tmp;
                    if (x - u <= v - x) {
                        cout << u << '\n';
                        s.erase(it);
                    } else {
                        cout << v << '\n';
                        s.erase(tmp);
                    }
                }
            }
        }
    }
    cout.flush();
    return 0;
}