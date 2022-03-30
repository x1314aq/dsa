#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int main() {
    int n;
    ios::sync_with_stdio(false);
    map<string, int> m;
    cin.tie(nullptr);
    cin >> n;
    int op, score;
    string name;
    for (int i = 0; i < n; i++) {
        cin >> op;
        if (op == 1) {
            cin >> name >> score;
            m[name] = score;
            cout << "OK\n";
        } else if (op == 2) {
            cin >> name;
            auto it = m.find(name);
            if (it == m.end()) {
                cout << "Not found\n";
            } else {
                cout << it->second << '\n';
            }
        } else if (op == 3) {
            cin >> name;
            auto it = m.find(name);
            if (it == m.end()) {
                cout << "Not found\n";
            } else {
                m.erase(it);
                cout << "Deleted successfully\n";
            }
        } else {
            cout << m.size() << '\n';
        }
    }
    cout.flush();
    return 0;
}