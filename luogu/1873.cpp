#include <bits/stdc++.h>

using namespace std;
using ll = long long int;
using pii = pair<int, int>;
using pil = pair<int, ll>;
using pll = pair<ll, ll>;

int n, m;
int a[1000005];

ll fn(int x) {
    ll sum = 0;
    int *i = upper_bound(a, a + n, x);
    while (i < a + n) {
        sum += *i - x;
        i++;
    }

    return sum;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a, a + n);
    int l = 1, r = 1000000000;
    int ans;
    while (l < r) {
        int mid = l + (r - l) / 2;
        if (fn(mid) >= m)
            l = mid + 1;
        else
            r = mid;
    }
    cout << l - 1 << endl;
    return 0;
}
