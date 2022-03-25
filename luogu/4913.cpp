#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

struct node {
    int l, r;
};

static node g_nodes[1000005];

static int depth(int n) {
    int hl = 0, hr = 0;

    if (g_nodes[n].l) {
        hl = depth(g_nodes[n].l);
    }

    if (g_nodes[n].r) {
        hr = depth(g_nodes[n].r);
    }

    return max(hl, hr) + 1;
}

int main() {
    int n;
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> g_nodes[i].l >> g_nodes[i].r;
    }

    cout << depth(1) << endl;
    return 0;
}