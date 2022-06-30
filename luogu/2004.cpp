#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int n, m, c;
int arr[1005][1005];

static ll line(int x, int y) {
    ll sum = 0;
    for (int i = 1; i <= c; i++) {
        sum += arr[x][y + i - 1];
    }
    return sum;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n >> m >> c;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> arr[i][j];
        }
    }
    for (int j = 1; j <= m; j++) {
        arr[0][j] = arr[c][j];
    }

    int x, y;
    ll sum = INT_MIN;
    for (int j = 1; j <= m - c + 1; j++) {
        ll cur = 0;
        for (int u = 1; u <= c; u++) {
            for (int v = j; v <= j + c - 1; v++) {
                cur += arr[u][v];
            }
        }
        for (int i = 1; i <= n - c + 1; i++) {
            cur = cur - line(i - 1, j) + line(i + c - 1, j);
            if (cur > sum) {
                sum = cur;
                x = i;
                y = j;
            }
        }
    }
    cout << x << ' ' << y << endl;
    return 0;
}
