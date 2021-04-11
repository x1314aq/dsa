//
// 1174 区间中最大的数
//

#include <bits/stdc++.h>

using namespace std;

int n, q;
int a[10005][20];

void pre_calc() {
    int k = log2((double)n);
    for (int j = 1; j <= k; j++)
        for (int i = 0; i + (1 << (j - 1)) < n; i++)
            a[i][j] = max(a[i][j - 1], a[i + (1 << (j - 1))][j - 1]);
}

int query(int l, int r) {
    int k = log2((double)(r - l + 1));
    return max(a[l][k], a[r - (1 << k) + 1][k]);
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i][0];

    pre_calc();

    vector<int> ans;
    cin >> q;
    for (int i = 0; i < q; i++) {
        int a, b;
        cin >> a >> b;
        ans.push_back(query(a, b));
    }

    for (int i = 0; i < q; i++)
        cout << ans[i] << endl;

    return 0;
}
