#include <bits/stdc++.h>

using namespace std;
using ll = long long int;

int n, m;
int a[105];
int f[10005];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];

    f[0] = 1;
    for(int i = 1; i <= n; i++)
        for(int j = m; j >= a[i]; j--)
            f[j] += f[j - a[i]];

    cout << f[m] << endl;
    return 0;
}
