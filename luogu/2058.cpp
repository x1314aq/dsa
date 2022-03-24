#include <bits/stdc++.h>

using namespace std;

int g_c[100005];

int main() {
    int n;
    queue<int> q;
    queue<vector<int>> v;
    int ans = 0;

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 0; i < n; i++) {
        int t, k;
        vector<int> u;

        cin >> t >> k;
        for (int j = 0; j < k; j++) {
            int a;
            cin >> a;
            u.push_back(a);
            if (g_c[a]++ == 0) {
                ans++;
            }
        }
        q.push(t);
        v.push(u);

        while (t - q.front() >= 86400) {
            q.pop();
            auto u = v.front();
            for (int p = 0; p < u.size(); p++) {
                if (--g_c[u[p]] == 0) {
                    ans--;
                }
            }
            v.pop();
        }
        cout << ans << '\n';
    }
    cout << endl;
    return 0;
}