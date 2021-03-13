#include <bits/stdc++.h>

using namespace std;
using ll = long long int;

int main() {
    string s;
    ll m;
    int n;
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> s >> m;
    ll sz = s.length();

    while (m > sz) {
        n = 0;
        while (m > sz * (1ll << n)) n++;
        m = m - sz * (1ll << (n - 1)) - 1;
        if (m == 0) m = sz * (1ll << (n - 1));
    }
    cout << s[m - 1] << endl;
    return 0;
}
