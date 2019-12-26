//
// 2636 卡车加油
//

#include <bits/stdc++.h>

using namespace std;

struct node {
    int a, b;
    node() = default;
    node(int a0, int b0) : a(a0), b(b0) {}
    bool operator <(const node &tmp) const {
        return a < tmp.a;
    }
};
node stations[10005];

int main() {
    priority_queue<int> pq;
    int l, p, n;

    cin >> l >> p >> n;
    for (int i = 0; i < n; i++)
        cin >> stations[i].a >> stations[i].b;
    sort(stations, stations + n);
    pq.push(p);

    int ans = -1;
    int acc = 0;
    node *last = stations - 1;
    while (!pq.empty()) {
        int tmp = pq.top();
        pq.pop();
        acc += tmp;
        ans++;
        if (acc >= l)
            break;
        auto it = lower_bound(stations, stations + n, node(acc, 0));
        for (auto i = last + 1; i <= it; i++)
            pq.push(i->b);
        last = it;
    }

    cout << (acc < l ? -1 : ans) << endl;
    return 0;
}
