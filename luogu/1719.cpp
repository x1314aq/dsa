#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int arr[125][125];

int fn(int *v, int n) {
    int f = v[1], g = v[1];
    for (int i = 2; i <= n; i++) {
        g = max(g + v[i], v[i]);
        f = max(f, g);
    }
    return f;
}

int main() {
    int n;
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> arr[i][j];
        }
    }
    int ans = INT_MIN;
    int v[125];
    for (int i = 1; i <= n; i++) {
        memset(v, 0, sizeof(v));
        for (int j = i; j >= 1; j--) {
            for (int k = 1; k <= n; k++) {
                v[k] += arr[j][k];
            }
            ans = max(ans, fn(v, n));
        }
    }
    cout << ans << endl;
    return 0;
}
