/**
 * hihoCoder 1105  题外话 堆
 * priority_queue
 */

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    vector<int> ans;
    priority_queue<int> pq;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int num;
        char c;
        cin >> c;
        if (c == 'A') {
            cin >> num;
            pq.push(num);
        } else {
            ans.push_back(pq.top());
            pq.pop();
        }
    }

    for (size_t i = 0; i < ans.size(); i++)
        cout << ans[i] << endl;
    return 0;
}
