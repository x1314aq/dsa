//
// 1906 子段统计
//

#include <bits/stdc++.h>

using namespace std;

int l, k;
string str;

int main() {
    cin >> l >> k;
    cin >> str;

    unordered_map<string, bool> dict;
    size_t len = str.length();
    for (int i = 0; i + l <= len; i++) {
        string s = str.substr(i, l);
        if (dict.find(s) == dict.end())
            dict[s] = true;
    }

    cout << dict.size() << endl;
    return 0;
}
