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

struct cmp {
    bool operator() (int a, int b) {
        return g_n[a].time < g_n[b].time;
    }
};

int main() {
    int n, ans;
    multiset<int, cmp> s;
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
            s.insert(i);
        }
    }

    while (!s.empty()) {
        int u = *s.cbegin();
        ans = g_n[u].time;
        s.erase(s.begin());
        for (auto it = g_n[u].v.cbegin(); it != g_n[u].v.cend(); ++it) {
            g_n[*it].in--;
            if (g_n[*it].in == 0) {
                g_n[*it].time += g_n[u].time;
                s.insert(*it);
            }
        }
    }
    cout << ans << endl;
    return 0;
}