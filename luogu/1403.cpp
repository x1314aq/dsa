#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

static int fn(int x) {
    if (x == 1)
        return 1;
    int n = 0;
    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0) {
            n += 2;
            if (i * i == x) {
                n--;
            }
        }
    }
    return n + 2;
}

int main() {
    int n;
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += n / i;
    }
    cout << sum << endl;
    return 0;
}