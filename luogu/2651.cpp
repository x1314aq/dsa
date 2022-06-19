#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int gcd(int x, int y) {
    int r;
    while (y) {
        r = x % y;
        x = y;
        y = r;
    }
    return x;
}

int main() {
    int t, n;
    int a1, a2;
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    for (int i = 0; i < t; i++) {
        cin >> n;
        cin >> a1 >> a2;
        a2 /= gcd(a1, a2);
        for (int j = 2; j < n; j++) {
            int x;
            cin >> x;
            a2 /= gcd(a2, x);
        }
        cout << (a2 == 1 ? "Yes\n" : "No\n");
    }
    cout.flush();
    return 0;
}

