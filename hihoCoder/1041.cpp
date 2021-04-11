/**
 * hihoCoder 1041  国庆出游
 * DFS + 剪枝
 */

#include <bits/stdc++.h>
using namespace std;

vector<int> cities[105];
bitset<128> bits[105];
int order[105];
int visited[105];

void init_bits(int cur, int parent) {
    bits[cur][cur] = 1;
    for (size_t i = 0; i < cities[cur].size(); i++) {
        int t = cities[cur][i];
        if (t == parent)
            continue;
        init_bits(t, cur);
        bits[cur] |= bits[t];
    }
}

int solve(int m) {
    int cnt = 1;
    vector<int> s;
    s.push_back(1);
    while (!s.empty()) {
        int u = s.back();
        s.pop_back();
        visited[u] = 1;
        if (u == order[cnt])
            cnt++;
        if (cnt == m)
            return 1;
        int next = order[cnt];
        for (size_t i = 0; i < cities[u].size(); i++) {
            int t = cities[u][i];
            if (bits[t][next] && !visited[t])
                s.push_back(t);
        }
    }
    return 0;
}

int main() {
    int t;
    int res[25];
    cin >> t;

    for (int i = 0; i < t; i++) {
        int n, m;
        cin >> n;
        for (int j = 1; j < n; j++) {
            int a, b;
            cin >> a >> b;
            cities[a].push_back(b);
            cities[b].push_back(a);
        }
        cin >> m;
        for (int j = 1; j <= m; j++) {
            cin >> order[j];
        }
        memset(visited, 0, 105 * sizeof(int));
        init_bits(1, 0);

        res[i] = solve(m);

        for (int j = 0; j < 105; j++) {
            cities[j].clear();
            bits[j].reset();
        }
    }

    for (int i = 0; i < t; i++)
        cout << (res[i] ? "YES" : "NO") << endl;

    return 0;
}
