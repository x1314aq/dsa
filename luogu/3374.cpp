#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int c[500005];
int n, m;

static int lowbit(int x) {
    return x & (-x);
}

static ll query(int x) {
    ll ans = 0;
    while (x) {
        ans += c[x];
        x -= lowbit(x);
    }
    return ans;
}

static ll query(int x, int y) {
    return query(y) - query(x - 1);
}

static void update(int x, int k) {
    while (x <= n) {
        c[x] += k;
        x += lowbit(x);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        int a;
        cin >> a;
        update(i, a);
    }
    for (int i = 1; i <= m; i++) {
        int op, x, k;
        cin >> op >> x >> k;
        if (op == 1) {
            update(x, k);
        } else {
            cout << query(x, k) << '\n';
        }
    }
    cout.flush();
    return 0;
}
