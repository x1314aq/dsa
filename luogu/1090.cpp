#include <bits/stdc++.h>

using namespace std;
using ll = long long int;
using pii = pair<int, int>;
using pil = pair<int, ll>;
using pll = pair<ll, ll>;

int n;

int main() {
    priority_queue<int, vector<int>, greater<int>> pq;
    ll ans = 0;
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        pq.push(a);
    }
    while (1) {
        int a = pq.top();
        pq.pop();
        if (pq.empty())
            break;
        int b = pq.top();
        pq.pop();
        ans += (a + b);
        pq.push(a + b);
    }
    cout << ans << endl;
    return 0;
}
