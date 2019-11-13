//
// 2423 叶子节点的数量
//

#include <bits/stdc++.h>

using namespace std;

vector<int> nodes[1005];

int main() {
    int n;

    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        int x, y;
        cin >> x >> y;
        nodes[x].push_back(y);
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (nodes[i].size() == 0)
            ans++;
    }

    cout << ans << endl;
    return 0;
}
