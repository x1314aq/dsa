/**
 * hihoCoder 1128  二分 二分查找之k小数
 * priority_queue with limited memory
 */

#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int main() {
    int n, k, temp;
    cin >> n >> k;
    priority_queue<int> pq;
    for(int i = 1; i <= k; i++) {
        cin >> temp;
        pq.push(temp);
    }
    for(int i = k + 1; i <= n; i++) {
        cin >> temp;
        int cur = pq.top();
        if(temp < cur) {
            pq.pop();
            pq.push(temp);
        }
    }
    cout << pq.top() << endl;
    return 0;
}
