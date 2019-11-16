//
// 1396 还是01串
//

#include <bits/stdc++.h>

using namespace std;

int main() {
    string s;
    vector<int> v;
    int cnt = 0;
    int cnt1;

    cin >> s;
    for (auto c : s) {
        v.push_back(cnt);
        if (c == '0')
            cnt++;
    }

    cnt1 = s.length() - cnt;
    int i;
    for (i = 0; i < s.length(); i++) {
        int tmp = cnt1 - (i - v[i]);
        if (tmp == v[i])
            break;
    }

    cout << i << endl;
    return 0;
}
