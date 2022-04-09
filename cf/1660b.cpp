#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int main() {
    int t;
    vector<int> v;
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        for (int i = 0; i < n; i++) {
            int u;
            cin >> u;
            v.push_back(u);
        }
        if (v.size() == 1) {
            if (v[0] == 1) {
                cout << "yes\n";
            } else {
                cout << "no\n";
            }
        } else {
            sort(v.begin(), v.end());
            if (v[n - 1] - v[n - 2] > 1) {
                cout << "no\n";
            } else {
                cout << "yes\n";
            }
        }
        v.clear();
    }
    return 0;
}