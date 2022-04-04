#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

struct node {
    int in;
    int time;
    vector<int> v;
};

static node g_n[10005];
static int g_a[10005];

int main() {
    int n;
    int ans = 0;
    queue<int> q;

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int cur, t, u;
        cin >> cur >> t >> u;
        g_n[cur].time = t;
        while (u) {
            g_n[cur].in++;
            g_n[u].v.push_back(cur);
            cin >> u;
        }
    }

    for (int i = 1; i <= n; i++) {
        if (g_n[i].in == 0) {
            q.push(i);
            g_a[i] = g_n[i].time;
        }
    }
    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (auto it = g_n[u].v.cbegin(); it != g_n[u].v.cend(); ++it) {
            g_n[*it].in--;
            if (g_n[*it].in == 0) {
                q.push(*it);
            }
            g_a[*it] = max(g_a[*it], g_a[u] + g_n[*it].time);
        }
    }
    for (int i = 1; i <= n; i++) {
        ans = max(ans, g_a[i]);
    }
    cout << ans << endl;
    return 0;
}