/**
 * hihoCoder 1097  最小生成树一Prim算法
 * Prim
 */


#include <bits/stdc++.h>
using namespace std;

int g[1005][1005];
int vis[1005];
int prio[1005];

int main() {
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            cin >> g[i][j];

    for(int i = 1; i <= n; i++)
        prio[i] = 0x7fffffff;
    int ans = 0;
    prio[1] = 0;
    for(int i = 1; i <= n; i++) {
        int smallest = 0x7fffffff;
        int u = 1;
        for(int j = 1; j <= n; j++) {
            if(!vis[j] && prio[j] < smallest) {
                smallest = prio[j];
                u = j;
            }
        }
        ans += prio[u];
        vis[u] = 1;
        for(int j = 1; j <= n; j++) {
            if(!vis[j] && prio[j] > g[u][j])
                prio[j] = g[u][j];
        }
    }

    cout << ans << endl;
    return 0;
}
