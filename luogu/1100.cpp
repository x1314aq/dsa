#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int main() {
    unsigned n;
    unsigned a;
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    a = ((n & 0xFFFF) << 16) | (n >> 16);
    cout << a << endl;
    return 0;
}