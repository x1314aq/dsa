//
// 1056 排座椅
//

#include <bits/stdc++.h>

using namespace std;

int row[1005], col[1005];

struct node {
    int index, num;
    bool operator<(const node &b) const { return num < b.num; }
};

int main() {
    int m, n, k, l, d;
    ios::sync_with_stdio(false);
    cin >> m >> n >> k >> l >> d;
    for (int i = 0; i < d; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        if (x1 == x2)
            col[min(y1, y2)]++;
        else
            row[min(x1, x2)]++;
    }

    priority_queue<node> q1, q2;
    vector<int> v;
    for (int i = 1; i <= m; i++) {
        q1.push(node{i, row[i]});
    }
    for (int i = 0; i < k; i++) {
        v.push_back(q1.top().index);
        q1.pop();
    }
    sort(v.begin(), v.end());
    for (auto it = v.begin(); it != v.end(); ++it)
        cout << *it << ' ';
    cout << endl;

    v.clear();
    for (int i = 1; i <= n; i++) {
        q2.push(node{i, col[i]});
    }
    for (int i = 0; i < l; i++) {
        v.push_back(q2.top().index);
        q2.pop();
    }
    sort(v.begin(), v.end());
    for (auto it = v.begin(); it != v.end(); ++it)
        cout << *it << ' ';
    cout << endl;

    return 0;
}
