//
// 2518 和为S
//

#include <bits/stdc++.h>

using namespace std;

int a[30005];
int b[30005];

int main() {
    int n, s;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    cin >> s;

    int ans = 0;
    int sum = 0;
    b[0] = 1;
    for (int i = 0; i < n; i++) {
        sum += a[i];
        if (sum >= s)
            ans += b[sum - s];
        b[sum]++;
    }

    cout << ans << endl;
    return 0;
}
