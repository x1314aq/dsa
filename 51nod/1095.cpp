//
// 1095 Anigram单词
//

#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, q;
    unordered_map<string, bool> dict0;
    unordered_map<string, int> dict;
    int alpha[256] = {0};

    cin >> n;
    for (int i = 0; i < n; i++) {
        string inp, s;

        cin >> inp;
        dict0[inp] = true;
        for (auto c : inp)
            alpha[c]++;
        for (int j = 0; j < 256; j++) {
            if (alpha[j]) {
                s.push_back(j);
                s.push_back('0' + alpha[j]);
                alpha[j] = 0;
            }
        }
        auto it = dict.find(s);
        if (it != dict.end())
            it->second++;
        else
            dict[s] = 1;
    }

    cin >> q;
    for (int i = 0; i < q; i++) {
        string inp, s;

        cin >> inp;
        for (auto c : inp)
            alpha[c]++;
        for (int j = 0; j < 256; j++) {
            if (alpha[j]) {
                s.push_back(j);
                s.push_back('0' + alpha[j]);
                alpha[j] = 0;
            }
        }
        int ans = 0;
        auto it = dict.find(s);
        if (it == dict.end())
            ans = 0;
        else {
            ans = it->second;
            if (dict0[inp])
                ans--;
        }
        cout << ans << endl;
    }
    return 0;
}
