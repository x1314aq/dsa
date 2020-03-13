//
// 2582 最短区间
//

#include <bits/stdc++.h>

using namespace std;
using ull = unsigned long long;

int n, s;
ull b[500005];

bool fn(int m) {
    for (int i = 1; i + m - 1 <= n; i++)
        if (b[i + m - 1] - b[i - 1] >= s)
            return true;
    return false;
}

int main() {
    ios::sync_with_stdio(false);

    cin >> s >> n;
    for (int i = 1; i <= n; i++) {
        ull tmp;
        cin >> tmp;
        b[i] = b[i - 1] + tmp;
    }

    int l = 0, r = n;
    int mid, ans = 0;
    while (l < r) {
        mid = (l + r) / 2;
        if (fn(mid))
            ans = r = mid;
        else
            l = mid + 1;
    }

    cout << ans << endl;
    return 0;
}
