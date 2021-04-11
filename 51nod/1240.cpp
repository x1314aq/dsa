//
// 1240 莫比乌斯函数
//

#include <bits/stdc++.h>

using namespace std;

int miu(int n) {
    if (n == 1)
        return 1;
    int res = 1;
    int len = sqrt(n);
    for (int i = 2; i <= len; i++)
        if (n % i == 0) {
            int cnt = 0;
            while (n % i == 0) {
                n /= i;
                cnt++;
            }
            if (cnt > 1)
                return 0;
            res *= -1;
        }
    if (n != 1)
        res *= -1;
    return res;
}

int main() {
    int n;
    cin >> n;
    cout << miu(n) << endl;
    return 0;
}
