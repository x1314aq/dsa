//
// 1116 车厢重组
//

#include <bits/stdc++.h>

using namespace std;

int arr[10005];

int main() {
    int n, ans = 0;
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < i; j++)
            if (arr[j] > arr[i])
                ans++;
    cout << ans << endl;
    return 0;
}
