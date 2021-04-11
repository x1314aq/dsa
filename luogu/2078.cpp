//
// 2078 朋友
//

#include <bits/stdc++.h>

using namespace std;

int a[10005], b[10005];
int aa[10005], bb[10005];

int find_a(int x) {
    return a[x] = (a[x] == x ? x : find_a(a[x]));
}

int find_b(int x) {
    return b[x] = (b[x] == x ? x : find_b(b[x]));
}

int main() {
    int n, m, p, q;
    ios::sync_with_stdio(false);
    cin >> n >> m >> p >> q;
    for (int i = 1; i <= n; i++) {
        a[i] = i;
        aa[i] = 1;
    }
    for (int i = 1; i <= m; i++) {
        b[i] = i;
        bb[i] = 1;
    }
    for (int i = 1; i <= p; i++) {
        int x, y;
        cin >> x >> y;
        if (x != y) {
            int fx = find_a(x);
            int fy = find_a(y);
            if (fx != fy) {
                if (fx == 1) {
                    a[fy] = fx;
                    aa[fx] += aa[fy];
                } else {
                    a[fx] = fy;
                    aa[fy] += aa[fx];
                }
            }
        }
    }
    for (int i = 1; i <= q; i++) {
        int x, y;
        cin >> x >> y;
        x *= -1;
        y *= -1;
        if (x != y) {
            int fx = find_b(x);
            int fy = find_b(y);
            if (fx != fy) {
                if (fx == 1) {
                    b[fy] = fx;
                    bb[fx] += bb[fy];
                } else {
                    b[fx] = fy;
                    bb[fy] += bb[fx];
                }
            }
        }
    }
    cout << min(aa[1], bb[1]) << endl;
    return 0;
}
