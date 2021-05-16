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
    for (int i = 0; i < n; i++)
        sum += a[i] / x;

    return sum;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    int l = 1, r = 100000000;
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
