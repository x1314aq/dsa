//
// 51nod 1130 N的阶乘的长度 V2
//

#include <bits/stdc++.h>

using namespace std;
using ull = unsigned long long;
const double pi = 3.14159265358979;
const double le = 0.43429448190325;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        double res = log10(2.0 * pi * n) / 2.0 + n * (log10(n) - le);
        cout << (ull)res + 1 << endl;
    }
    return 0;
}
