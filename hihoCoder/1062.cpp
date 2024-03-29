/**
 * hihoCoder 1062  最近公共祖先一
 */

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n;
    map<string, string> dict;
    string father, son, son1, son2;
    for (int i = 0; i < n; i++) {
        cin >> father >> son;
        dict[son] = father;
    }
    cin >> m;
    while (m--) {
        cin >> son1 >> son2;
        set<string> rec;
        while (dict.count(son1)) {
            rec.insert(son1);
            son1 = dict[son1];
        }
        rec.insert(son1);
        bool status = false;
        while (dict.count(son2)) {
            if (rec.count(son2)) {
                cout << son2 << endl;
                status = true;
                break;
            }
            son2 = dict[son2];
        }
        if (!status && rec.find(son2) != rec.end()) {
            cout << son2 << endl;
            status = true;
        }
        if (!status)
            cout << -1 << endl;
    }
    return 0;
}
