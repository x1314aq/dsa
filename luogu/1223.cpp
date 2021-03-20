#include <bits/stdc++.h>

using namespace std;
using ll = long long int;

int n;
pair<int, int> a[1005];

int main() {
    ll total = 0;
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i].first;
        a[i].second = i;
    }

    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; i++) {
        cout << a[i].second << ' ';
        total += (n - i) * a[i].first;
    }
    cout << endl;
    cout << fixed << setprecision(2) << (double)total / (double)n << endl;
    return 0;
}
