//
// 1073 约瑟夫环
//

#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    int res = 0;
    for (int i = 2; i <= n; i++)
        res = (res + k) % i;
    cout << res + 1 << endl;
    return 0;
}
