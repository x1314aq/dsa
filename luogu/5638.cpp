#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

ll arr[1000005];

int main() {
    int n, k;
    ll sum = 0;
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> k;
    for (int i = 1; i <= n - 1; i++) {
        cin >> arr[i];
        sum += arr[i];
    }

    ll a = 0;
    if (k != 0) {
        ll b = 0;
        for (int i = 1; i <= k; i++) {
            b += arr[i];
        }
        a = max(a, b);
        for (int i = k + 1; i < n; i++) {
            b = b - arr[i - k] + arr[i];
            a = max(a, b);
        }
    }
    cout << sum - a << endl;
    return 0;
}
