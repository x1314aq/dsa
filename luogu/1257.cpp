#include <bits/stdc++.h>

using namespace std;
using ll = long long;

double x[10005], y[10005];

static inline double distance(int i, int j) {
    double a = x[i] - x[j];
    double b = y[i] - y[j];
    return sqrt(a * a + b * b);
}

int main() {
    int n;
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
    }
    double ans = 2 * 10e9;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            ans = min(ans, distance(i, j));
        }
    }

    cout.setf(ios::fixed);
    cout << setprecision(4) << ans << endl;
    return 0;
}
