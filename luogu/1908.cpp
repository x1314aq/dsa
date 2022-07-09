#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int arr[500005];
int sorted[500005];
ll ans;

static void fn(int l, int r) {
    if (r - l < 2)
        return;

    int m = l + (r - l) / 2;
    fn(l, m);
    fn(m, r);

    int x = l, y = m;
    int z = l;
    while (x < m && y < r) {
        if (arr[x] <= arr[y]) {
            sorted[z++] = arr[x++];
        } else {
            sorted[z++] = arr[y++];
            ans += m - x;
        }
    }
    if (x == m) {
        while (y < r) {
            sorted[z++] = arr[y++];
        }
    }
    if (y == r) {
        while (x < m) {
            sorted[z++] = arr[x++];
        }
    }
    copy_n(sorted + l, r - l, arr + l);
}

int main() {
    int n;
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    fn(0, n);
    cout << ans << endl;
    return 0;
}
