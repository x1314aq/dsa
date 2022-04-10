#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

static int g_a[1005];
static int g_m[1005][1005];
static bool g_is[1005];

int main() {
    int n, m, a;
    vector<int> v(1005);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> a;
        memset(g_is, 0, sizeof(g_is));
        for (int j = 1; j <= a; j++) {
            cin >> v[j];
            g_is[v[j]] = true;
        }
        for (int j = v[1]; j <= v[a]; j++) {
            if (!g_is[j]) {
                for (int k = 1; k <= a; k++) {
                    if (!g_m[v[k]][j]) {
                        g_m[v[k]][j] = 1;
                        g_a[j]++;
                    }
                }
            }
        }
    }

    queue<int> q;
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (g_a[i] == 0) {
            q.push(i);
        }
    }
    q.push(0);
    while (!q.empty()) {
        int a = q.front();
        q.pop();

        if (a == 0) {
            ans++;
            if (q.empty()) {
                break;
            }
            q.push(0);
            continue;
        }

        for (int i = 1; i <= n; i++) {
            if (g_m[a][i]) {
                g_a[i]--;
                if (g_a[i] == 0) {
                    q.push(i);
                }
                g_m[a][i] = 0;
            }
        }
    }
    cout << ans << endl;
    return 0;
}