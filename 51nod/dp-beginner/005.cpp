//
// 最长单增子序列
//

#include <bits/stdc++.h>

using namespace std;

int arr[50005];
int asd[50005];

int main() {
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> arr[i];

    int res = 1;
    int len = 1;
    asd[0] = arr[0];
    for(int i = 1; i < n; i++) {
        int l = 0, r = len;
        while(l < r) {
            int mid = (l + r) / 2;
            if(asd[mid] <= arr[i])
                l = mid + 1;
            else
                r = mid;
        }
        len = max(len, l + 1);
        asd[l] = arr[i];
        res = max(res, l + 1);
    }
    cout << res << endl;
    return 0;
}
