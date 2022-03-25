#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int main() {
    int n;
    queue<pii> q;
    pii u, v;
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 1; i <= (1 << n); i++) {
        int a;
        cin >> a;
        q.push(make_pair(i, a));
    }
    while (q.size() > 2) {
        u = q.front();
        q.pop();
        v = q.front();
        q.pop();

        if (u.second > v.second) {
            q.push(u);
        } else {
            q.push(v);
        }
    }

    u = q.front();
    q.pop();
    v = q.front();
    q.pop();

    if (u.second > v.second) {
        cout << v.first << endl;
    } else {
        cout << u.first << endl;
    }
    return 0;
}