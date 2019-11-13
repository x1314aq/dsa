//
// 2281 树的size之和
//

#include <bits/stdc++.h>

using namespace std;

vector<int> nodes[1005];

int depth(int n, int &ans) {
    if (nodes[n].size() == 0) {
        ans += 1;
        return 1;
    }

    int nums = 0;
    for (int i = 0; i < nodes[n].size(); i++)
        nums += depth(nodes[n][i], ans);

    ans += nums + 1;
    return nums + 1;
}

int main() {
    int n;

    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        int x, y;
        cin >> x >> y;
        nodes[x].push_back(y);
    }

    int ans = 0;
    depth(1, ans);
    cout << ans << endl;
    return 0;
}
