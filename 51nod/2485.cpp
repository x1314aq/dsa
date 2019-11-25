//
// 2485 小b重排字符串
//

#include <bits/stdc++.h>

using namespace std;

int main() {
    string str;
    int len;
    int dict[256] = {0};
    int most = 0;

    cin >> str;
    len = str.length();
    for (int i = 0; i < len; i++)
        dict[str[i]]++;
    for (int i = 0; i < 256; i++)
        if (dict[i] > most)
            most = dict[i];

    if (len & 1) {
        if (most > (len + 1) / 2)
            cout << "Impossible" << endl;
        else
            cout << "Possible" << endl;
    }
    else {
        if (most > len / 2)
            cout << "Impossible" << endl;
        else
            cout << "Possible" << endl;
    }

    return 0;
}
