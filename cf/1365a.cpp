//
// 1365A Matrix Game
//

#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    ios::sync_with_stdio(false);
    cin >> t;
    while (t--) {
        int g[55][55];
        int n, m;
        cin >> n >> m;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> g[i][j];
        int a = 0, b = 0;
        for (int i = 0; i < n; i++) {
            int s = 0;
            for (int j = 0; j < m; j++)
                s += g[i][j];
            if (s == 0) a++;
        }

        for (int j = 0; j < m; j++) {
            int s = 0;
            for (int i = 0; i < n; i++)
                s += g[i][j];
            if (s == 0) b++;
        }
        if (min(a, b) & 1) cout << "Ashish" << endl;
        else cout << "Vivek" << endl;
    }
}
