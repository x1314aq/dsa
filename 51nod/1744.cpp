//
// 1744 被盗的食物
//

#include <bits/stdc++.h>

using namespace std;
using ull = unsigned long long;

int main() {
    ull n;
    ull maximum, minimum;
    ull u, v;
    set<ull> factors;

    cin >> n;
    maximum = 9 * (n + 1);
    minimum = 9 * (n + 1);
    for (ull i = 1; i <= (ull)floor(sqrt((double)n)); i++) {
        if (n % i == 0) {
            factors.insert(i);
            factors.insert(n / i);
        }
    }
    for (auto u : factors) {
        v = n / u;
        for (ull i = (ull)floor(sqrt((double)u)); i >= 1; i--) {
            if (u % i == 0) {
                minimum = min(minimum, (v + 1) * (u + 2 * (i + u / i) + 4));
                break;
            }
        }
    }
    cout << minimum - n << ' ' << maximum - n << endl;

    return 0;
}
