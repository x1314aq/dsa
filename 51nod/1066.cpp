//
// 1066 Bash游戏
//

#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    while(n--) {
        int a, b;
        cin >> a >> b;
        if(a % (b + 1) == 0)
            cout << 'B' << endl;
        else
            cout << 'A' << endl;
    }
    return 0;
}
