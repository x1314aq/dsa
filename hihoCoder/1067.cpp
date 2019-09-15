/**
 * hihoCoder 1067  最近公共祖先二
 * 离线算法+并查集
 */


#include <bits/stdc++.h>
using namespace std;

string name[100005];
vector<int> g[100005];
map<string, int> dict;
vector<int> query[100005];
string qleft[100005], qright[100005];
int ans[100005];
int sup[100005];
int cnt = 1;

int find(int x) {
    return sup[x] = sup[x] == x ? x : find(sup[x]);
}

void dfs(int u, int f) {
    int sz = g[u].size();
    int qsz = query[u].size();

    sup[u] = u;
    for(int i = 0; i < sz; i++)
        dfs(g[u][i], u);
    for(int i = 0; i < qsz; i++) {
        int tmp = query[u][i];
        int target;
        if(u == dict[qleft[tmp]])
            target = dict[qright[tmp]];
        else
            target = dict[qleft[tmp]];
        if(!find(target))
            continue;
        ans[tmp] = find(target);
    }
    sup[u] = find(f);
}

int main() {
    int n, m;

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

    cin >> m;
    for(int i = 0; i < m; i++) {
        cin >> qleft[i] >> qright[i];
        int p1 = dict[qleft[i]];
        int p2 = dict[qright[i]];
        query[p1].push_back(i);
        query[p2].push_back(i);
    }

    dfs(1, 1);

    for(int i = 0; i < m; i++)
        cout << name[ans[i]] << endl;
    return 0;
}
