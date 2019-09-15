/**
 * hihoCoder 1069  最近公共祖先三
 * 在线算法+RMQ-ST
 */


#include <bits/stdc++.h>
using namespace std;

const int maxn = 100005;

vector<int> g[maxn];
string name[maxn];
map<string, int> dict;
int cnt = 1;
int arr[200005][25];
int degree[maxn], reverse_degree[200005];
int n, m;

static void dfs(int u) {
    degree[u] = cnt;
    reverse_degree[degree[u]] = u;
    arr[cnt++][0] = degree[u];

    int sz = g[u].size();
    for(int i = 0; i < sz; i++) {
        dfs(g[u][i]);
        arr[cnt++][0] = degree[u];
    }
}

static void pre_calc() {
    int t = int(log2(cnt));
    for(int j = 1; j <= t; j++)
        for(int i = 1; i + (1 << (j - 1)) - 1 <= cnt; i++)
            arr[i][j] = min(arr[i][j - 1], arr[i + (1 << (j - 1))][j - 1]);
}

static int query(int l, int r) {
    int t = int(log2(r - l + 1));
    return min(arr[l][t], arr[r - (1 << t) + 1][t]);
}

int main() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        string f, s;
        cin >> f >> s;
        if(!dict[f]) {
            name[cnt] = f;
            dict[f] = cnt++;
        }
        if(!dict[s]) {
            name[cnt] = s;
            dict[s] = cnt++;
        }
        int fi = dict[f];
        int si = dict[s];
        g[fi].push_back(si);
    }

    cnt = 1;
    dfs(1);
    pre_calc();

    cin >> m;
    vector<int> ans;
    for(int i = 0; i < m; i++) {
        string p1, p2;
        cin >> p1 >> p2;
        int d1 = dict[p1];
        int d2 = dict[p2];
        ans.push_back(query(min(degree[d1], degree[d2]), max(degree[d1], degree[d2])));
    }
    for(int i = 0; i < m; i++)
        cout << name[reverse_degree[ans[i]]] << endl;

    return 0;
}
