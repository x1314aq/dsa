#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int main() {
    int n, k;
    // set<int> row, col;
    vector<int> row, col;
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> k;
    for (int i = 0; i < k; i++) {
        int u, v;
        cin >> u >> v;
        row.push_back(u);
        col.push_back(v);
    }
    sort(row.begin(), row.end());
    sort(col.begin(), col.end());
    size_t su = 0, sv = 0;
    for (int i = 0; i < k; i++) {
        if (row[i] != row[i + 1]) {
            su++;
        }
        if (col[i] != col[i + 1]) {
            sv++;
        }
    }
    cout << (su + sv) * (size_t)n - (su * sv) << endl;
    return 0;
}