/**
 * hihoCoder 1109  最小生成树三堆优化堆Prim算法
 * Prim + priority_queue
 */

#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

vector<pii> vs[100005];
int vis[100005];

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v, cost;
        scanf("%d %d %d", &u, &v, &cost);
        vs[u].push_back(pii(cost, v));
        vs[v].push_back(pii(cost, u));
    }

    priority_queue<pii, vector<pii>, greater<pii>> pq;
    vis[1] = 1;
    for (size_t i = 0; i < vs[1].size(); i++)
        pq.push(pii(vs[1][i]));
    int ans = 0;
    while (!pq.empty()) {
        pii cur = pq.top();
        pq.pop();
        if (!vis[cur.second]) {
            vis[cur.second] = 1;
            ans += cur.first;
            for (size_t i = 0; i < vs[cur.second].size(); i++) {
                if (!vis[vs[cur.second][i].second])
                    pq.push(pii(vs[cur.second][i]));
            }
        }
    }

    printf("%d\n", ans);
    return 0;
}
