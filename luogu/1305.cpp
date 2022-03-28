#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

struct node {
    char c, l, r;
};

static node g_nodes[100];
int n;

static void fn(char x) {
    if (x != '*') {
        cout << x;
        for (int i = 0; i < n; i++) {
            if (g_nodes[i].c == x) {
                fn(g_nodes[i].l);
                fn(g_nodes[i].r);
            }
        }
    }
}

int main() {
    char c, l, r;
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> g_nodes[i].c >> g_nodes[i].l >> g_nodes[i].r;
    }

    fn(g_nodes[0].c);
    cout << endl;
    return 0;
}