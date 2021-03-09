#include <bits/stdc++.h>

using namespace std;
using ll = long long int;

ll w[25][25][25];
bool vis[25][25][25];

ll dfs(ll a, ll b, ll c) {
    ll ans;
    if (a <= 0 || b <= 0 || c <= 0)
        return 1;
    if (vis[a][b][c]) return w[a][b][c];
    if (a < b && b < c)
        ans = dfs(a, b, c - 1) + dfs(a, b - 1, c - 1) - dfs(a, b - 1, c);
    else
        ans = dfs(a - 1, b, c) + dfs(a - 1, b - 1, c) + dfs(a - 1, b, c - 1) - dfs(a - 1, b - 1, c - 1);
    w[a][b][c] = ans;
    vis[a][b][c] = true;
    return ans;
}

int main() {
    ll a, b, c, ans;
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    while (1) {
        scanf("%lld %lld %lld", &a, &b, &c);
        if (a == -1 && b == -1 && c == -1) break;
        if (a <= 0 || b <= 0 || c <= 0)
            ans = 1;
        else if (a > 20 || b > 20 || c > 20)
            ans = dfs(20, 20, 20);
        else
            ans = dfs(a, b, c);
        printf("w(%lld, %lld, %lld) = %lld\n", a, b, c, ans);
    }
    return 0;
}
