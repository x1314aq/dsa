#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

struct node {
    int l, r;
};

static node g_nodes[105];
static int n;

static int depth(int x) {
    int hl = 0, hr = 0;

    if (g_nodes[x].l) {
        hl = depth(g_nodes[x].l);
    }
    if (g_nodes[x].r) {
        hr = depth(g_nodes[x].r);
    }
    return max(hl, hr) + 1;
}

static int breadth() {
    int ans = 1;
    queue<int> q;

    q.push(1);
    q.push(0);
    while (!q.empty()) {
        int u = q.front();
        q.pop();

        if (u == 0) {
            int v = q.size();
            if (v == 0) {
                break;
            }
            ans = max(ans, v);
            q.push(0);
            continue;
        }

        if (g_nodes[u].l) {
            q.push(g_nodes[u].l);
        }
        if (g_nodes[u].r) {
            q.push(g_nodes[u].r);
        }
    }

    return ans;
}

static int do_dist(int x, int u) {
    int dis_l, dis_r;

    if (x == u) {
        return 0;
    }

    if (g_nodes[x].l == u || g_nodes[x].r == u) {
        return 1;
    }

    if (g_nodes[x].l) {
        dis_l = do_dist(g_nodes[x].l, u);
        if (dis_l != INT_MAX) {
            return dis_l + 1;
        }
    }

    if (g_nodes[x].r) {
        dis_r = do_dist(g_nodes[x].r, u);
        if (dis_r != INT_MAX) {
            return dis_r + 1;
        }
    }

    return INT_MAX;
}

static int __dist(int x, int u, int v) {
    int dis_u = do_dist(x, u);
    int dis_v = do_dist(x, v);

    if (dis_u != INT_MAX && dis_v != INT_MAX) {
        return 2 * dis_u + dis_v;
    }
    return INT_MAX;
}

static int distance(int u, int v) {
    int ans = INT_MAX;
    for (int i = 1; i < n; i++) {
        ans = min(ans, __dist(i, u, v));
    }

    return ans;
}

int main() {
    int u, v;
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 1; i < n; i++) {
        cin >> u >> v;
        if (g_nodes[u].l == 0) {
            g_nodes[u].l = v;
        } else {
            g_nodes[u].r = v;
        }
    }
    cin >> u >> v;
    cout << depth(1) << '\n' << breadth() << '\n' << distance(u, v) << endl;
    return 0;
}