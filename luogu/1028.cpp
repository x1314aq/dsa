#include <bits/stdc++.h>

using namespace std;
using ll = long long int;

int main() {
    int n;
    int f[1001] = {0};
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= i / 2; ++j) {
            f[i] += f[j];
        }
        f[i]++;
    }

    cout << f[n] << endl;
    return 0;
}
