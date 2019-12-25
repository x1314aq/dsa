//
// 1010 只包含因子2 3 5的数
//

#include <bits/stdc++.h>

using namespace std;
using ull = unsigned long long;

ull num[60000];
int asize = 0;

void init() {
    for (ull i = 1; i < 1e18 + 999; i *= 2)
        for(ull j = 1; j * i < 1e18 + 999; j *= 3)
            for (ull k = 1; k * j * i < 1e18 + 999; k *= 5)
                num[asize++] = i * j * k;
    sort(num, num + asize);
}

int main() {
    int n;

    init();
    cin >> n;
    while (n--) {
        ull tmp;
        cin >> tmp;
        auto it = lower_bound(num + 1, num + asize, tmp);
        cout << *it << endl;
    }

    return 0;
}
