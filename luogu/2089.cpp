#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> ans;
int n;

void fn(int i, int sum, vector<int> &v) {
    if (i == 10) {
        if (sum == n) {
            ans.push_back(v);
        }
        return;
    }
    for (int j = 1; j <= 3; j++) {
        v.push_back(j);
        fn(i + 1, sum + j, v);
        v.pop_back();
    }
}

void solve() {
    vector<int> v;
    for (int i = 1; i <= 3; i++) {
        v.push_back(i);
        fn(1, i, v);
        v.pop_back();
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    solve();
    cout << ans.size() << endl;
    for (size_t i = 0; i < ans.size(); i++) {
        for (size_t j = 0; j < ans[i].size(); j++)
            cout << ans[i][j] << ' ';
        cout << endl;
    }
    return 0;
}
