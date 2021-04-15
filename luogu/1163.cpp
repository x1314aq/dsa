#include <bits/stdc++.h>

using namespace std;
using ll = long long int;
using pii = pair<int, int>;
using pil = pair<int, ll>;
using pll = pair<ll, ll>;

double n, m, k, l, r;
bool pd(double x) {
    return (pow(1.0 / (1.0 + x), k) >= 1 - n / m * x);
}

int main() {
    cin >> n >> m >> k;
    l = 0;
    r = 10;
    while (r - l >= 0.0001) {
        double mid = (l + r) / 2;
        if (pd(mid))
            r = mid;
        else
            l = mid;
    }
    cout << fixed << setprecision(1) << l * 100 << endl;
    return 0;
}
