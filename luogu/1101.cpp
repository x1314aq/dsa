#include <bits/stdc++.h>

using namespace std;
using ll = long long int;
using pii = pair<int, int>;
using pil = pair<int, ll>;
using pll = pair<ll, ll>;

int n;
char g[105][105];
bool vis[105][105];
char ss[] = "yizhong";

#define fn(i, j, x, y, k)                                                                                              \
    if (!((i + k * x >= 0 && i + k * x < n && j + k * y >= 0 && j + k * y < n) && g[i + k * x][j + k * y] == ss[k]))   \
    continue
#define st(i, j, x, y, k) vis[i + k * x][j + k * y] = true

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> g[i];
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (g[i][j] != 'y')
                continue;
            for (int x = -1; x < 2; ++x) {
                for (int y = -1; y < 2; ++y) {
                    if (x == 0 && y == 0)
                        continue;
                    fn(i, j, x, y, 1);
                    fn(i, j, x, y, 2);
                    fn(i, j, x, y, 3);
                    fn(i, j, x, y, 4);
                    fn(i, j, x, y, 5);
                    fn(i, j, x, y, 6);
                    st(i, j, x, y, 0);
                    st(i, j, x, y, 1);
                    st(i, j, x, y, 2);
                    st(i, j, x, y, 3);
                    st(i, j, x, y, 4);
                    st(i, j, x, y, 5);
                    st(i, j, x, y, 6);
                }
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (vis[i][j])
                cout << g[i][j];
            else
                cout << '*';
        }
        cout << endl;
    }
    return 0;
}
