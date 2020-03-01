//
// 1432 独木舟
//

#include <bits/stdc++.h>

using namespace std;

int n, m;
int a[10005];

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> a[i];

    sort(a, a + n);

    int ans = n;
    for (int i = 0, j = n - 1; i < j; i++, j--) {
        while (i < j && a[i] + a[j] > m)
            j--;
        if (i < j)
            ans--;
    }

    cout << ans << endl;
    return 0;
}
