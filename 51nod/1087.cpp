//
// 1087 1 10 100 1000
//

#include <bits/stdc++.h>

using namespace std;
map<int, bool> dict;

int main() {
    for (int i = 1; i < 45000; i++)
        dict[1 + i * (i - 1) / 2] = true;

    int n;
    
    cin >> n;
    while (n--) {
        int num;

        cin >> num;
        if (dict[num])
            cout << 1 << endl;
        else
            cout << 0 << endl;
    }
    return 0;
}
