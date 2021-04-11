//
// 3958 奶酪
//

#include <bits/stdc++.h>

using namespace std;

int sup[1005];
int ax[1005], ay[1005], az[1005];

int find(int x) {
    return sup[x] = (x == sup[x] ? x : find(sup[x]));
}

void join(int x, int y) {
    int fx = find(x);
    int fy = find(y);
    if (fx != fy)
        sup[fx] = fy;
}

#define SQ(x) ((double)(x) * (double)(x))
int main() {
    int T, n, h, r;
    ios::sync_with_stdio(false);
    cin >> T;
    while (T--) {
        cin >> n >> h >> r;
        sup[0] = 0;
        for (int i = 1; i <= n; i++) {
            cin >> ax[i] >> ay[i] >> az[i];
            sup[i] = i;
        }
        sup[n + 1] = n + 1;
        for (int i = 1; i <= n; i++) {
            if (az[i] + r >= h)
                join(0, i);
            if (az[i] <= r)
                join(n + 1, i);
            for (int j = i + 1; j <= n; j++) {
                double d = sqrt(SQ(ax[i] - ax[j]) + SQ(ay[i] - ay[j]) + SQ(az[i] - az[j]));
                if (!(d / 2 > (double)r))
                    join(i, j);
            }
        }
        if (find(0) == find(n + 1))
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    return 0;
}
