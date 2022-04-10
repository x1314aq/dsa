#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int main() {
    int t, n, m;
    char s[128];
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    while (t--) {
        memset(s, 0, sizeof(s));
        m = 0;
        cin >> n >> s;
        for (int i = 0; i < n;) {
            if (s[i] == '0') {
                if (s[i + 1] == '0') {
                    m += 2;
                    i += 1;
                } else {
                    if (s[i + 2] == '0') {
                        m += 1;
                    }
                    i += 2;
                }
                continue;
            }
            i++;
        }
        cout << m << '\n';
    }
    cout.flush();
    return 0;
}