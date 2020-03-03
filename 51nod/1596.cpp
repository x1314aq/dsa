//
// 1596 搬货物
//

#include <bits/stdc++.h>

using namespace std;

int n;
int w[1000100];

int main() {
    int up = -1;
    ios::sync_with_stdio(false);

    cin >> n;
    for (int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        w[tmp]++;
        while (w[tmp] > 1) {
            w[tmp] -= 2;
            w[++tmp]++;
        }
        up = max(up, tmp);
    }

    int ans = 0;
    for (int i = 0; i <= up; i++)
        if (w[i]) ans++;

    cout << ans << endl;
    return 0;
}
