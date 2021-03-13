#include <bits/stdc++.h>

using namespace std;
using ll = long long int;

int f[1000005];
int g[1000005];

int main() {
    int n;
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;

    f[1] = 1;
    f[2] = 2;
    g[1] = 1;
    g[2] = 2;
    for (int i = 3; i <= n; ++i) {
        f[i] = (f[i - 1] + f[i - 2] + 2 * g[i - 2]) % 10000;
        g[i] = (f[i - 1] + g[i - 1]) % 10000;
    }
    cout << f[n] << endl;
    return 0;
}
