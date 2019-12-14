//
// 1065 最小正子段和
//

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

struct node {
    ll sum;
    int index;
};

node nodes[50005];

bool cmp(const node &a, const node &b) {
    return a.sum < b.sum ? true : (a.sum == b.sum ? a.index < b.index : false);
}

int main() {
    int n;

    cin >> n;
    for (int i = 1; i <= n; i++) {
        int tmp;
        cin >> tmp;
        nodes[i].sum = nodes[i - 1].sum + tmp;
        nodes[i].index = i;
    }

    sort(nodes, nodes + n + 1, cmp);
    ll ans = INT_MAX;
    for (int i = 0; i < n; i++) {
        if (nodes[i].index > nodes[i + 1].index)
            continue;
        if (nodes[i].sum == nodes[i + 1].sum)
            continue;
        ans = min(ans, nodes[i + 1].sum - nodes[i].sum);
    }

    cout << ans << endl;
    return 0;
}
