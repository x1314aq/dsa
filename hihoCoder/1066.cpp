/**
 * hihoCoder 1066  无间道之并查集
 */

#include <bits/stdc++.h>
using namespace std;

int superior[200005];
unordered_map<string, int> names;

int find(int x) {
    int r = x;
    while (superior[r] != r)
        r = superior[r];

    int i = x, j;
    while (i != r) {
        j = superior[i];
        superior[i] = r;
        i = j;
    }
    return r;
}

void join(int x, int y) {
    int fx = find(x);
    int fy = find(y);
    if (fx != fy)
        superior[fx] = fy;
}

int main() {
    int n;
    int men = 1;
    vector<string> ans;
    cin >> n;
    for (int i = 1; i < 200005; i++)
        superior[i] = i;
    for (int i = 0; i < n; i++) {
        int op;
        string s1, s2;
        cin >> op >> s1 >> s2;
        if (op == 0) {
            int a, b;
            if (names.find(s1) == names.end()) {
                names[s1] = men;
                a = men;
                men++;
                if (names.find(s2) == names.end()) {
                    names[s2] = men;
                    b = men;
                    men++;
                } else
                    b = names[s2];
            } else {
                a = names[s1];
                if (names.find(s2) == names.end()) {
                    names[s2] = men;
                    b = men;
                    men++;
                } else
                    b = names[s2];
            }
            join(a, b);
        } else {
            if (names.find(s1) == names.end() || names.find(s2) == names.end())
                ans.push_back("no");
            else {
                int a = find(names[s1]);
                int b = find(names[s2]);
                ans.push_back((a == b ? "yes" : "no"));
            }
        }
    }
    for (size_t i = 0; i < ans.size(); i++)
        cout << ans[i] << endl;
    return 0;
}
