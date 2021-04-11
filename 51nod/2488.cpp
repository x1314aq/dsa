//
// 51nod 2488 矩形并的面积
//

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ll x1, x2, y1, y2, x3, x4, y3, y4;

    cin >> x1 >> y1 >> x2 >> y2;
    cin >> x3 >> y3 >> x4 >> y4;
    ll ans = (x2 - x1) * (y2 - y1) + (x4 - x3) * (y4 - y3);
    x1 = max(x1, x3);
    y1 = max(y1, y3);
    x2 = min(x2, x4);
    y2 = min(y2, y4);
    if (x1 <= x2 && y1 <= y2)
        ans -= (x2 - x1) * (y2 - y1);
    cout << ans << endl;
    return 0;
}
