#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

struct node {
    int p, l, r, w;
};

static node g_nodes[105];
static ll g_dist[105][105];

static ll fn(int x, int y) {
    vector<int> v;
    ll ans = 0;

    v.push_back(x);
    while (g_nodes[x].p) {
        v.push_back(g_nodes[x].p);
        x = g_nodes[x].p;
    }

    while (y) {
        auto it = find(begin(v), end(v), y);
        if (it != end(v)) {
            ans += (it - begin(v));
            break;
        }
        y = g_nodes[y].p;
        ans++;
    }
    return ans;
}

int main() {
    int n;
    ll ans = LONG_LONG_MAX;
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;

    for (int i = 1; i <= n; i++) {
        int l, r;
        cin >> g_nodes[i].w >> l >> r;
        g_nodes[i].l = l;
        g_nodes[i].r = r;
        g_nodes[l].p = i;
        g_nodes[r].p = i;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == j) {
                continue;
            }
            g_dist[i][j] = fn(i, j);
        }
    }

    for (int i = 1; i <= n; i++) {
        ll tmp = 0;
        for (int j = 1; j <= n; j++) {
            tmp += g_nodes[j].w * g_dist[j][i];
        }
        ans = min(ans, tmp);
    }
    cout << ans << endl;
    return 0;
}