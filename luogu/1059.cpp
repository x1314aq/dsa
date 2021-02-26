#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    set<int> s;
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        s.insert(a);
    }
    cout << s.size() << endl;
    for (auto it = s.begin(); it != s.end(); ++it) {
        cout << *it << ' ';
    }
    cout.flush();
    return 0;
}
