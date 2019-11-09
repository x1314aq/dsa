//
// 1347 旋转字符串
//

#include <bits/stdc++.h>

using namespace std;

int main() {
    string s;

    cin >> s;
    if (s.length() & 1)
        cout << "NO" << endl;
    else {
        int sz = s.length() / 2;
        bool yes = true;
        for (int i = 0; i < sz; i++) {
            if (s[i] != s[i + sz]) {
                yes = false;
                break;
            }
        }
        cout << (yes ? "YES" : "NO") << endl;
    }
    return 0;
}
