//
// 2653 区间xor
//

#include <bits/stdc++.h>

using namespace std;

int fn(int x) {
    switch (x % 4) {
    case 0:
        return x;
    case 1:
        return 1;
    case 2:
        return x + 1;
    case 3:
        return 0;
    }
    return x;
}

int main() {
    int a, b, ans;

    cin >> a >> b;
    cout << (fn(a - 1) ^ fn(b)) << endl;
    return 0;
}
