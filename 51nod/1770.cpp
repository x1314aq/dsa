//
// 1770 数数字
//

#include <bits/stdc++.h>

using namespace std;

int main() {
    int T;
    int a, b, d, n;
    while (cin >> T) {
        for (int i = 0; i < T; ++i) {
            int cnt = 0;
            cin >> a >> b >> d >> n;
            int temp = a * 1000 + a * 100 + a * 10 + a;
            temp *= b;
            if (n == 1) {
                int val = a * b;
                if (val % 10 == d) {
                    cnt++;
                }
                if (val >= 10 && val / 10 == d)
                    cnt++;
                cout << cnt << endl;
                continue;
            }
            int m = 0;
            while (temp) {
                int bit = 0;
                bit = temp % 10;
                temp /= 10;
                if (bit == d) {
                    if (m == 2)
                        cnt += (n - 3);
                    else
                        cnt++;
                }
                ++m;
            }
            cout << cnt << endl;
        }
    }
    return 0;
}
