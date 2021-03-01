#include <bits/stdc++.h>

using namespace std;

int main() {
    int l, n;
    int ans1 = 0, ans2 = 0;
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> l >> n;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        ans1 = max(ans1, min(a, l + 1 - a));
        ans2 = max(ans2, max(a, l + 1 - a));
    }
    cout << ans1 << ' ' << ans2 << endl;
    return 0;
}