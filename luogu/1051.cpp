//
// 1051 谁拿了最多奖学金
//

#include <bits/stdc++.h>

using namespace std;
using ull = unsigned long long;

int main() {
    int n;
    string name;
    ull total = 0;
    ull ans = 0;
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 0; i < n; i++) {
        string s;
        int a, b, e;
        char c, d;
        ull tmp = 0;
        cin >> s >> a >> b >> c >> d >> e;
        if (a > 80 && e >= 1)
            tmp += 8000;
        if (a > 85 && b > 80)
            tmp += 4000;
        if (a > 90)
            tmp += 2000;
        if (a > 85 && d == 'Y')
            tmp += 1000;
        if (b > 80 && c == 'Y')
            tmp += 850;
        total += tmp;
        if (tmp > ans) {
            name = s;
            ans = tmp;
        }
    }
    cout << name << endl;
    cout << ans << endl;
    cout << total << endl;
    return 0;
}
