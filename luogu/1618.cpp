#include <bits/stdc++.h>

using namespace std;
vector<vector<int>> ans;
bool used[10];
int a, b, c;

bool ok(vector<int> &v) {
    int n1 = 100 * v[0] + 10 * v[1] + v[2];
    int n2 = 100 * v[3] + 10 * v[4] + v[5];
    int n3 = 100 * v[6] + 10 * v[7] + v[8];
    if (n1 * b == n2 * a && n1 * c == n3 * a)
        return true;
    else
        return false;
}

void fn(int i, vector<int> &v) {
    if (i == 8) {
        if (ok(v)) {
            ans.push_back(v);
        }
        return;
    }
    for (int j = 1; j <= 9; j++) {
        if (!used[j]) {
            v[i + 1] = j;
            used[j] = true;
            fn(i + 1, v);
            used[j] = false;
        }
    }
}

void solve() {
    vector<int> v(9);
    for (int i = 1; i <= 9; i++) {
        v[0] = i;
        used[i] = true;
        fn(0, v);
        used[i] = false;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> a >> b >> c;
    solve();
    if (ans.empty()) {
        cout << "No!!!" << endl;
    }
    else {
        for (size_t i = 0; i < ans.size(); i++) {
            for (int j = 0; j < 3; j++) {
                int n = 100 * ans[i][j * 3] + 10 * ans[i][j * 3 + 1] + ans[i][j * 3 + 2];
                cout << n << ' ';
            }
            cout << endl;
        }
    }
    return 0;
}
