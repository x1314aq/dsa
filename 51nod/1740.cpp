//
// 1740 蜂巢迷宫
//

#include <bits/stdc++.h>

using namespace std;
using ull = unsigned long long;
using ll = long long;

const int maximum = 577350269;

ull find(ull n) {
    ull l = 0, r = maximum;
    ull mid;

    while (l + 1 < r) {
        mid = (l + r) / 2;
        ull res = 3 * mid * (mid + 1);
        if (res <= n)
            l = mid;
        else
            r = mid;
    }
    return l;
}

int main() {
    ull n, k, q;
    ll x, y;
    
    cin >> n;
    k = find(n);
    q = n - 3 * k * (k + 1);
    x = 2 * k;
    y = 0;

    if (k == 0) {
        switch(q) {
        case 1:
            x = 1;
            y = 2;
            goto out;
        case 2:
            x = -1;
            y = 2;
            goto out;
        case 3:
            x = -2;
            y = 0;
            goto out;
        case 4:
            x = -1;
            y = -2;
            goto out;
        case 5:
            x = 1;
            y = -2;
            goto out;
        }
    }
    if (q == 1) {
        x += 1;
        y += 2;
    }
    else if (q > 1 && q <= 1 + k) {
        x -= (q - 2);
        y += 2 * q;
    }
    else if (q > 1 + k) {
        x -= (k - 1);
        y += 2 * (k + 1);
        q -= (1 + k);
        int a = q / (1 + k);
        int b = q - a * (1 + k);

        if (a == 0) {
            x -= 2 * b;
        }
        else {
            x -= 2 * (k + 1);
            if (a == 1) {
                x -= b;
                y -= 2 * b;
                if (b == 0)
                    goto out;
            }
            else {
                x -= (k + 1);
                y -= 2 * (k + 1);
                if (a == 2) {
                    x += b;
                    y -= 2 * b;
                    if (b == 0)
                        goto out;
                }
                else {
                    x += (k + 1);
                    y -= 2 * (k + 1);
                    if (a == 3) {
                        x += 2 * b;
                        if (b == 0)
                            goto out;
                    }
                    else {
                        x += 2 * (k + 1);
                        if (a == 4) {
                            x += b;
                            y += 2 * b;
                        }
                    }
                }
            }
        }
    }

out:
    cout << x << ' ' << y << endl;
    return 0;
}
