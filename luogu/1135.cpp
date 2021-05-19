#include <bits/stdc++.h>

using namespace std;
using ll = long long int;
using pii = pair<int, int>;
using pil = pair<int, ll>;
using pll = pair<ll, ll>;

int n, a, b;
int k[205];
bool vis[205];
int g[205];

int main() {
    int step = 0;
    queue<int> q;
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> a >> b;
    for (int i = 1; i <= n; i++) {
        cin >> k[i];
        g[i] = -1;
    }
    q.push(a);
    q.push(-1);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        if (u == -1) {
            if (q.empty())
                break;
            q.push(-1);
            step++;
            continue;
        }
        vis[u] = true;
        g[u] = step;
        if (u == b)
            break;
        if (u + k[u] <= n && !vis[u + k[u]])
            q.push(u + k[u]);
        if (u - k[u] >= 1 && !vis[u - k[u]])
            q.push(u - k[u]);
    }
    cout << g[b] << endl;
    return 0;
}
