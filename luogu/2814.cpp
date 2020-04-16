//
// 2814 家谱
//

#include <bits/stdc++.h>

using namespace std;

int sup[50005];

int find(int x) {
    return sup[x] = (x == sup[x] ? x : find(sup[x]));
}

int main() {
    char c;
    string a;
    int fa;
    unordered_map<string, int> dict;
    unordered_map<int, string> rdict;
    int idx = 0;
    ios::sync_with_stdio(false);
    for (int i = 0; i < 50005; i++)
        sup[i] = i;
    cin >> c;
    while (c != '$') {
        string b;
        if (c == '#') {
            cin >> a;
            if (dict.find(a) == dict.end()) {
                dict[a] = idx;
                rdict[idx] = a;
                idx++;
            }
        }
        else if (c == '+'){
            int fb;
            cin >> b;
            if (dict.find(b) == dict.end()) {
                dict[b] = idx;
                rdict[idx] = b;
                idx++;
            }
            fa = find(dict[a]);
            fb = find(dict[b]);
            sup[fb] = fa;
        }
        else {
            int fb;
            cin >> b;
            cout << b << ' ' << rdict[find(dict[b])] << endl;
        }
        cin >> c;
    }

    return 0;
}
