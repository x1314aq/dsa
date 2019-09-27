//
// 1069 Nim游戏
//

#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    int start = 0;
    while(n--) {
        int tmp;
        cin >> tmp;
        start ^= tmp;
    }

    if(start == 0)
        cout << 'B' << endl;
    else
        cout << 'A' << endl;
    return 0;
}
