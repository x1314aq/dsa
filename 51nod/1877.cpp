//
// 1877 打包
//

#include <bits/stdc++.h>

using namespace std;

int goods[7];

int main() {
    int ans = 0;

    for (int i = 1; i < 7; i++)
        cin >> goods[i];

    ans += goods[6];

    ans += goods[5];
    goods[1] -= 11 * goods[5];
    goods[1] = max(goods[1], 0);

    ans += goods[4];
    if (goods[2] > 0) {
        if (goods[2] >= goods[4] * 5)
            goods[2] -= goods[4] * 5;
        else {
            goods[1] -= (20 * goods[4] - 4 * goods[2]);
            goods[1] = max(goods[1], 0);
            goods[2] = 0;
        }
    }
    else if (goods[1] > 0) {
        goods[1] -= 20 * goods[4];
        goods[1] = max(goods[1], 0);
    }

    int a = goods[3] / 4;
    int b = goods[3] - 4 * a;
    ans += a;
    if (b > 0) {
        ans++;
        int c;
        switch (b) {
        case 1:
            c = 5;
            break;
        case 2:
            c = 3;
            break;
        case 3:
            c = 1;
            break;
        }
        if (goods[2] >= c) {
            goods[2] -= c;
            goods[1] -= (36 - b * 9 - c * 4);
            goods[1] = max(goods[1], 0);
        }
        else {
            int d = 36 - b * 9 - goods[2] * 4;
            goods[1] -= d;
            goods[1] = max(goods[1], 0);
            goods[2] = 0;
        }
    }

    a = goods[2] / 9;
    b = goods[2] - 9 * a;
    ans += a;
    if (b > 0) {
        ans++;
        int c = 36 - b * 4;
        goods[1] -= c;
        goods[1] = max(goods[1], 0);
    }

    a = goods[1] / 36;
    b = goods[1] - 36 * a;
    ans += a;
    if (b > 0)
        ans++;

    cout << ans << endl;
    return 0;
}
