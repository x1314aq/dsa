//
// 1024 矩阵中不重复的元素
//

#include <bits/stdc++.h>

using namespace std;

double arr[10005];

int main() {
    int m, n, a, b, c = 0;

    cin >> m >> n >> a >> b;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            arr[c++] = (b + j) * log((double)(a + i));

    sort(arr, arr + c);
    int ans = 1;
    for (int i = 0; i < c - 1; i++)
        if (abs(arr[i] - arr[i + 1]) > 1e-8)
            ans++;

    cout << ans << endl;
    return 0;
}
