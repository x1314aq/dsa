#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int c[500005];
int n, m;

static int lowbit(int x) {
    return x & (-x);
}

static int query(int x) {
    int ans = 0;
    while (x) {
        ans += c[x];
        x -= lowbit(x);
    }
    return ans;
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
    int a, b;
    cin >> a;
    update(1, a);
    for (int i = 2; i <= n; i++) {
        cin >> b;
        update(i, b - a);
        a = b;
    }
    for (int i = 1; i <= m; i++) {
        int op, x, y, k;
        cin >> op;
        if (op == 1) {
            cin >> x >> y >> k;
            update(x, k);
            update(y + 1, -k);
        } else {
            cin >> x;
            cout << query(x) << '\n';
        }
    }
    cout.flush();
    return 0;
}
