//
// 1334 瑞瑞的木板
//

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    priority_queue<ll, vector<ll>, greater<ll>> pq;
    int n;
    ll ans = 0;

    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        pq.push(tmp);
    }

    while (pq.size() > 1) {
        int u = pq.top();
        pq.pop();
        int v = pq.top();
        pq.pop();
        pq.push(u + v);
        ans += (u + v);
    }

    cout << ans << endl;
    return 0;
}
