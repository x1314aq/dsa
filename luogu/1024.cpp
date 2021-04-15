#include <bits/stdc++.h>

using namespace std;
using ll = long long int;
using pii = pair<int, int>;
using pil = pair<int, ll>;
using pll = pair<ll, ll>;

double a, b, c, d;

double eq(double x) {
    return a * x * x * x + b * x * x + c * x + d;
}

int main() {
    double ans[3];
    double l, r, m, x1, x2;
    int s = 0, i;
    cin >> a >> b >> c >> d;
    for (i = -100; i < 100; i++) {
        l = i;
        r = i + 1;
        x1 = eq(l);
        x2 = eq(r);
        if (!x1) {
            ans[s++] = l;
        }
        if (x1 * x2 < 0) {
            while (r - l >= 0.001) {
                m = (l + r) / 2;
                if (eq(m) * eq(r) <= 0)
                    l = m;
                else
                    r = m;
            }
            ans[s++] = r;
        }
        if (s == 3)
            break;
    }
    cout << fixed << setprecision(2) << ans[0] << ' ' << ans[1] << ' ' << ans[2] << endl;
    return 0;
}
