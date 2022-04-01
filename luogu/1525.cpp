#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

struct edge {
    int u, v, w;
};

static edge g_edges[100005];
static int g_a[20005];
static int g_b[20005];

static int find(int x) {
    int fx = x == g_a[x] ? x : find(g_a[x]);
    g_a[x] = fx;
    return fx;
}

static void join(int x, int y) {
    int fx = find(x);
    int fy = find(y);
    g_a[fy] = fx;
}

static bool cmp(edge const &a, edge const &b) {
    return a.w > b.w;
}

int main() {
    int n, m;
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        cin >> g_edges[i].u >> g_edges[i].v >> g_edges[i].w;
    }
    sort(g_edges + 1, g_edges + m + 1, cmp);

    for (int i = 1; i <= n; i++) {
        g_a[i] = i;
    }

    for (int i = 1; i <= m + 1; i++) {
        if (find(g_edges[i].u) == find(g_edges[i].v)) {
            cout << g_edges[i].w << endl;
            break;
        } else {
            if (!g_b[g_edges[i].u]) {
                g_b[g_edges[i].u] = g_edges[i].v;
            } else {
                join(g_b[g_edges[i].u], g_edges[i].v);
            }

            if (!g_b[g_edges[i].v]) {
                g_b[g_edges[i].v] = g_edges[i].u;
            } else {
                join(g_b[g_edges[i].v], g_edges[i].u);
            }
        }
    }
    return 0;
}