#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;
int g_cities[1000][1000];

int main() {
    int n;
    int ans = 0;
    string a, b;
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> a >> b;
        x = (a[0] - 'A') * 26 + (a[1] - 'A');
        y = (b[0] - 'A') * 26 + (b[1] - 'A');
        if (x != y) {
            g_cities[x][y]++;
            ans += g_cities[y][x];
        }
    }
    cout << ans << endl;
    return 0;
}