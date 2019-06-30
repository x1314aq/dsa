/**
 * hihoCoder 1128  二分 二分查找
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, k;
    int start = 1;
    int exist = 0;
    cin >> n >> k;
    for(int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        if(temp < k) start++;
        else if(temp == k) exist = 1;
    }
    cout << (exist ? start : -1) << endl;
    return 0;
}
