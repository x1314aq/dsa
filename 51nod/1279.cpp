//
// 1279  扔盘子
//

#include <bits/stdc++.h>

using namespace std;

int arr[50005];

int main() {
    int index = 0;
    int N, M;
    scanf("%d %d", &N, &M);
    for (int i = 0; i < N; i++) {
        int tmp;
        scanf("%d", &tmp);
        if (index == 0)
            arr[index++] = tmp;
        else {
            int cur = arr[index - 1];
            arr[index++] = tmp > cur ? cur : tmp;
        }
    }

    int ans = 0;
    for (int i = 0; i < M; i++) {
        int tmp;
        scanf("%d", &tmp);
        int j;
        for (j = N - 1; j >= 0; j--) {
            if (arr[j] >= tmp)
                break;
        }
        if (j == -1)
            break;
        ans++;
        N = j;
    }

    printf("%d\n", ans);
    return 0;
}
