//
// 1991 无线通讯网
//

#include <bits/stdc++.h>

using namespace std;

struct edge {
    int from, to;
    double d;
    bool operator<(const edge &a) const { return d < a.d; }
} e[250005];
int x[505], y[505], n;
int sup[505];

int find(int x) {
    return sup[x] = (x == sup[x] ? x : find(sup[x]));
}

#define SQ(x) ((x) * (x))
int main() {
    int s, p;
    ios::sync_with_stdio(false);
    cin >> s >> p;
    for (int i = 1; i <= p; i++) {
        cin >> x[i] >> y[i];
        for (int j = 1; j < i; j++) {
            n++;
            e[n].from = i;
            e[n].to = j;
            e[n].d = sqrt(SQ(x[i] - x[j]) + SQ(y[i] - y[j]));
        }
    }
    for (int i = 1; i <= p; i++)
        sup[i] = i;
    sort(e + 1, e + n + 1);
    double ans;
    int m = 0;
    for (int i = 1; i <= n; i++) {
        int fa = find(e[i].from);
        int fb = find(e[i].to);
        if (fa != fb) {
            sup[fa] = fb;
            ans = e[i].d;
            m++;
            if (m >= p - s)
                break;
        }
    }
    cout.flags(ios::fixed);
    cout.precision(2);
    cout << ans << endl;
    return 0;
}
