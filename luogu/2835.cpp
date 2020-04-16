//
// 2835 刻录光盘
//

#include <bits/stdc++.h>

using namespace std;

int sup[205], arr[205];

int find(int x) {
    return sup[x] = (x == sup[x] ? x : find(sup[x]));
}

int main() {
    int n;
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; i++)
        sup[i] = i;
    for (int i = 1; i <= n; i++) {
        int s;
        int fa, fs;
        cin >> s;
        fa = find(i);
        while (s) {
            fs = find(s);
            arr[s] = 1;
            if (fa != fs)
                sup[fs] = fa;
            cin >> s;
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)
        if (sup[i] == i || arr[i] == 0)
            ans++;
    cout << ans << endl;
    return 0;
}
