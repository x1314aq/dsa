#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int arr[1005][1005];

int main() {
    int n, m;
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        for (int j = x1; j <= x2; j++) {
            arr[j][y1] += 1;
            arr[j][y2 + 1] -= 1;
        }
    }
    for (int i = 1; i <= n; i++) {
        int sum = 0;
        for (int j = 1; j <= n; j++) {
            sum += arr[i][j];
            cout << sum << ' ';
        }
        cout << '\n';
    }
    cout.flush();
    return 0;
}
