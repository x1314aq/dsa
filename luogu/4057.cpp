#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

ll gcd(ll x, ll y) {
    ll r;
    while (y) {
        r = x % y;
        x = y;
        y = r;
    }
    return x;
}

ll lcm(ll x, ll y) {
    return x * y / gcd(x, y);
}

int main() {
    ll a, b, c;
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> a >> b >> c;
    cout << lcm(lcm(a, b), c) << endl;
    return 0;
}