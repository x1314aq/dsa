//
// 51nod 1137 矩阵乘法
//

#include <bits/stdc++.h>

using namespace std;
using ull = unsigned long long;

ull m1[105][105];
ull m2[105][105];

int main() {
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            cin >> m1[i][j];

    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            cin >> m2[j][i];

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            ull sum = 0;
            for(int k = 1; k <= n; k++)
                sum += m1[i][k] * m2[j][k];
            cout << sum << " ";
        }
        cout << endl;
    }
    return 0;
}
