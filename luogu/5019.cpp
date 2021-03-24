#include <bits/stdc++.h>

using namespace std;
using ll = long long int;
using pii = pair<int, int>;
using pil = pair<int, ll>;
using pll = pair<ll, ll>;

int n;
int d[1000005];
int ans;

void fn(int l, int r, int s) {
    if (l == r) return;
    if (l + 1 == r) {
        ans += d[l] - s;
        return;
    }
    int v = d[l];
    int m = l;
    for (int i = l; i < r; ++i) {
        if (d[i] < v) {
            m = i;
            v = d[i];
        }
    }
    ans += v - s;
    fn(l, m, v);
    fn(m + 1, r, v);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> d[i];
    }
    fn(0, n, 0);
    cout << ans << endl;
    return 0;
}
