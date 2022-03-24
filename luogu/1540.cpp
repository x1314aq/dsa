#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m;
    int ans = 0;
    bool inqueue[1005];
    queue<int> q;

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    for (int i = 0; i < 1005; i++) {
        inqueue[i] = false;
    }

    cin >> m >> n;
    for (int i = 0; i < n; i++) {
        int k;
        cin >> k;
        if (inqueue[k]) {
            continue;
        }
        if (q.size() == m) {
            int u = q.front();
            q.pop();
            inqueue[u] = false;
        }
        q.push(k);
        inqueue[k] = true;
        ans++;
    }
    cout << ans << endl;
    return 0;
}