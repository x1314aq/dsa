//
// 2497 数三角形
//

#include <bits/stdc++.h>

using namespace std;

int n, a[1005], ans;

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    sort(a + 1, a + 1 + n);
    for (int i = 1; i <= n - 1; i++) {
        for (int j = i + 1; j <= n; j++) {
            int k = lower_bound(a + 1, a + 1 + n, a[i] + a[j]) - a - 1;
            if (k >= j)
                ans += k - j;
        }
    }

    cout << ans << endl;
    return 0;
}
