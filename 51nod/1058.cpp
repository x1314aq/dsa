//
// 51nod 1058 N的阶乘的长度
//

#include <bits/stdc++.h>

using namespace std;
using ull = unsigned long long;

int main() {
    int n;
    cin >> n;

    double num = 1;
    for(int i = 2; i <= n; i++)
        num += log10((double)i);
    cout << (int)num << endl;
    return 0;
}
