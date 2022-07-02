#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

char g[1024][2048];

int main() {
    int n, length = 4, k = 1;
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n;
    for (int i = 0; i < 1024; i++) {
        for (int j = 0; j < 2048; j++) {
            g[i][j] = ' ';
        }
    }
    g[0][0] = g[1][1] = '/';
    g[0][1] = g[0][2] = '_';
    g[0][3] = g[1][2] = '\\';

    while (k < n) {
        for (int i = 0; i < length / 2; i++) {
            for (int j = 0; j < length; j++) {
                g[i + length / 2][j + length / 2] = g[i][j + length] = g[i][j];
            }
        }
        length *= 2;
        k++;
    }

    for (int i = length / 2 - 1; i >= 0; i--) {
        for (int j = 0; j < length; j++) {
            cout << g[i][j];
        }
        cout << '\n';
    }
    cout.flush();
    return 0;
}
