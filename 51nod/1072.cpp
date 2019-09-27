//
// 1072 威佐夫游戏
//

#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    const double c = (sqrt(5.0) + 1.0) / 2.0;
    while(n--) {
        int a, b;
        cin >> a >> b;
        int a0 = min(a, b);
        int b0 = max(a, b);
        if((int)((b0 - a0) * c) == a0)
            cout << 'B' << endl;
        else
            cout << 'A' << endl;
    }
    return 0;
}
