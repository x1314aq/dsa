//
// 1428 活动安排问题
//

#include <bits/stdc++.h>

using namespace std;

struct node {
    int time;
    int type;
};

enum {
    OUT = 0,
    IN = 1,
};

bool cmp(node &a, node &b) {
    return a.time < b.time ? true : (a.time == b.time ? a.type <= b.type : false);
}

node nodes[20005];

int main() {
    int n;

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> nodes[2 * i].time >> nodes[2 * i + 1].time;
        nodes[2 * i].type = IN;
        nodes[2 * i + 1].type = OUT;
    }

    sort(nodes, nodes + 2 * n, cmp);

    int ans = 0, sum = 0;
    for (int i = 0; i < 2 * n; i++) {
        if (nodes[i].type == IN)
            sum++;
        else
            sum--;
        ans = max(ans, sum);
    }

    cout << ans << endl;
    return 0;
}
