//
// 3367 并查集模板
//

#include <bits/stdc++.h>

using namespace std;

int sup[10005];

int find(int x) {
    return sup[x] = (x == sup[x] ? x : find(sup[x]));
}

void join(int x, int y) {
    int fx = find(x);
    int fy = find(y);
    if (fx != fy)
        sup[fx] = fy;
}

int main() {
    int n, m;
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        sup[i] = i;
    for (int i = 0; i < m; i++) {
        int z,x,y;
        cin >> z >> x >> y;
        if (z == 2) {
            if (find(x) == find(y))
                cout << 'Y' << endl;
            else
                cout << 'N' << endl;
        }
        else join(x, y);
    }

    return 0;
}
