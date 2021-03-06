#include <bits/stdc++.h>

using namespace std;
using ll = long long int;

int n;
int a[1005];

int main() {
    ll x, y, z;
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> x;
    for (int i = 0; i < n - 1; i++) {
        cin >> y;
        z = abs(x - y);
        if (z < n)
            a[z]++;
        x = y;
    }

    string ans = "Jolly";
    for (int i = 1; i < n; ++i) {
        if (a[i] != 1) {
            ans = "Not jolly";
            break;
        }
            
    }
    cout << ans << endl;
    return 0;
}
