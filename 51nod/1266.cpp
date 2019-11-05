//
// 1266 蚂蚁
//

#include <bits/stdc++.h>

using namespace std;

int main() {
    int l, n;
    int ans1 = 0, ans2 = 0;

    cin >> n >> l;
    for (int i = 0; i < n; i++) {
        int pos;
        cin >> pos;
        ans1 = max(ans1, min(pos, l - pos));
        ans2 = max(ans2, max(pos, l - pos));
    }

    cout << ans1 << ' ' << ans2 << endl;
    return 0;
}
