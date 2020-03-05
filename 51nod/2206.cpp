//
// 2206 低买高卖
//

#include<bits/stdc++.h>

using namespace std;
using ull = unsigned long long;

int n;

int main() {
    ull ans = 0;
    ios::sync_with_stdio(false);

    cin >> n;
    priority_queue<int, vector<int>, greater<int>> q;
    for(int i = 0; i < n; i++) {
        int tmp;
		cin >> tmp;
        q.push(tmp);
        q.push(tmp);
        ans += tmp - q.top();
        q.pop();
    }
    cout << ans << endl;
    return 0;
}
