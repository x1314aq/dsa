#include <bits/stdc++.h>

using namespace std;
using ll = long long int;
using pii = pair<int, int>;
using pil = pair<int, ll>;
using pll = pair<ll, ll>;

int n, m;
int a[100005];

int fn(int x) {
    int s = 0;
    int t = 0;
    for (int i = 0; i < n; i++) {
        if (t + a[i] <= x)
            t += a[i];
        else {
            t = a[i];
            s++;
        }
    }
    return s;
}

int main() {
    int l = 1, r = 0;
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        l = max(l, a[i]);
        r += a[i];
    }
    while (l < r) {
        int mid = l + (r - l) / 2;
        if (fn(mid) >= m)
            l = mid + 1;
        else
            r = mid;
    }
    cout << l << endl;
    return 0;
}
