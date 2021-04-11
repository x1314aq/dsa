//
// 1134 最长递增子序列
//

#include <bits/stdc++.h>

int arr[50005];
int ends[50005];

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &arr[i]);

    int res = 1;
    int len = 1;
    ends[1] = arr[1];
    for (int i = 2; i <= n; i++) {
        int l = 1, r = len + 1;
        while (l < r) {
            int mid = (l + r) / 2;
            if (ends[mid] <= arr[i])
                l = mid + 1;
            else
                r = mid;
        }
        if (l > len)
            len = l;
        ends[l] = arr[i];
        if (l > res)
            res = l;
    }
    printf("%d\n", res);
    return 0;
}
