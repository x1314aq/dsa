#include <bits/stdc++.h>

using namespace std;
using ll = long long int;
using pii = pair<int, int>;
using pil = pair<int, ll>;
using pll = pair<ll, ll>;

int d, n, m;
int a[100005];

int fn(int x) {
    int s = 0;
    for (int i = 0; i < n - 1; i++) {
        int t = a[i + 1] - a[i];
        if (t > x) {
            s += t / x;
            if (t % x == 0)
                s--;
        }
    }

    return s;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> d >> n >> m;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    int l = 1, r = a[n - 1];
    while (l < r) {
        int mid = l + (r - l) / 2;
        if (fn(mid) > m)
            l = mid + 1;
        else
            r = mid;
    }
    cout << l << endl;
    return 0;
}
