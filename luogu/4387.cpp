#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int main() {
    int n, m;
    vector<int> u;

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n; i++) {
        stack<int> s;
        cin >> m;
        u.clear();
        for (int j = 0; j < m; j++) {
            int k;
            cin >> k;
            u.push_back(k);
        }
        auto it = u.cbegin();
        for (int j = 0; j < m; j++) {
            int k;
            cin >> k;
            if (!s.empty() && s.top() == k) {
                s.pop();
                continue;
            }
            while (it != u.cend() && *it != k) {
                s.push(*it);
                ++it;
            }
            if (it != u.cend()) {
                ++it;
            }
        }
        cout << (s.empty() ? "Yes\n" : "No\n");
    }
    cout << endl;
    return 0;
}