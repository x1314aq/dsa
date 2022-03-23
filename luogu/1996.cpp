#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m, k;
    vector<int> v;

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    v.resize(n);
    for (int i = 0; i < n; i++) {
        v[i] = i + 1;
    }
    k = 0;
    auto it = v.begin();
    auto end = v.end();
    int i = 1;
    while (true) {
        if (i == m) {
            k++;
            cout << *it << ' ';
            *it = 0;
            if (k == n) {
                break;
            }
            i = 1;
            while (true) {
                ++it;
                if (it == end) {
                    it = v.begin();
                }
                if (*it != 0) {
                    break;
                }
            }
        } else {
            ++i;
            while (true) {
                ++it;
                if (it == end) {
                    it = v.begin();
                }
                if (*it != 0) {
                    break;
                }
            }
        }
    }
    cout << endl;
    return 0;
}