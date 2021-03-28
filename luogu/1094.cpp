#include <bits/stdc++.h>

using namespace std;
using ll = long long int;
using pii = pair<int, int>;
using pil = pair<int, ll>;
using pll = pair<ll, ll>;

int w, n;
int a[30005];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> w >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a, a + n);
    int ans = 0;
    int i = n - 1, j = 0;
    while (i >= j) {
        if (a[i] + a[j] > w) {
            ans++;
            i--;
        }
        else {
            ans++;
            i--;
            j++;
        }
    }

    cout << ans << endl;
    return 0;
}
