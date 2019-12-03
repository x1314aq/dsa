//
// 1106 质数检测
//

#include <bits/stdc++.h>

using namespace std;

const char *is_prime(int n) {
    for (int i = 2; i < (int)floor(sqrt((double)n) + 0.5); i++) {
        if (n % i == 0)
            return "No";
    }
    return "Yes";
}

int main() {
    int n;
    cin >> n;
    while (n--) {
        int tmp;
        cin >> tmp;
        cout << is_prime(tmp) << endl;
    }
    return 0;
}
