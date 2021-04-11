/**
 * hihoCoder 1050  树中的最长路
 */

#include <bits/stdc++.h>
using namespace std;

struct vertex {
    vector<int> neighs;
    void append(int a) { neighs.push_back(a); }
};

vertex vs[100005];
bool visit[100005];
int first[100005];
int second[100005];

static void dfs(int v) {
    int sz = vs[v].neighs.size();
    visit[v] = 1;

    vector<int> tmp;
    for (int i = 0; i < sz; i++) {
        int u = vs[v].neighs[i];
        if (visit[u])
            continue;

        if (!first[u])
            dfs(u);
        tmp.push_back(first[u]);
    }

    if (tmp.size() == 0) {
        first[v] = 0;
    } else if (tmp.size() == 1) {
        first[v] = tmp[0] + 1;
    } else {
        sort(tmp.begin(), tmp.end(), greater<int>());
        first[v] = tmp[0] + 1;
        second[v] = tmp[1] + 1;
    }
}

int main() {
    int n;

    scanf("%d", &n);
    for (int i = 1; i <= n - 1; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        vs[a].append(b);
        vs[b].append(a);
    }

    dfs(1);

    int ans = first[1] + second[1];
    for (int i = 2; i <= n; i++) {
        int tmp = first[i] + second[i];
        if (tmp > ans)
            ans = tmp;
    }

    printf("%d\n", ans);
    return 0;
}
