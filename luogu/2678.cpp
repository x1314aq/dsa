#include <bits/stdc++.h>

using namespace std;
using ll = long long int;
using pii = pair<int, int>;
using pil = pair<int, ll>;
using pll = pair<ll, ll>;

int d, n, m;
int a[50005];

int fn(int x) {
    int now = 0, next = 0;
    int total = 0;

    while (next < n + 1) {
        next++;
        if (a[next] - a[now] < x)
            total++;
        else
            now = next;
    }
    return total;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> d >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    a[n + 1] = d;
    int l = 1, r = d + 1;
    while (l < r) {
        int mid = l + (r - l) / 2;
        if (fn(mid) <= m)
            l = mid + 1;
        else
            r = mid;
    }
    cout << l - 1 << endl;
    return 0;
}
