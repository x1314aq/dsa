//
// 1413 权势二进制
//

#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    int ans = 0;

    cin >> n;
    for (; n; n /= 10)
        ans = max(ans, n % 10);
    cout << ans << endl;
    return 0;
}
