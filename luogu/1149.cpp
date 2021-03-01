#include <bits/stdc++.h>

using namespace std;
using ll = long long int;

const int a[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};

int calc(int n) {
    int sum = 0;
    if (n == 0) return a[0];
    while (n) {
        sum += a[n % 10];
        n /= 10;
    }
    return sum;
}

int main() {
    int ans = 0;
    int n;
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 0; i < 1111; ++i) {
        for (int j = 0; j < 1111; ++j) {
            if (i == j)
                continue;
            if (calc(i) + calc(j) + calc(i + j) + 4 == n)
                ans++;
        }
    }
    for (int i = 0; i < 1111; ++i) {
        if (calc(i) + calc(i) + calc(i + i) + 4 == n)
            ans++;
    }

    cout << ans << endl;
    return 0;
}
