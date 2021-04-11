/**
 * hihoCoder 1518  最大集合
 */

#include <bits/stdc++.h>
using namespace std;

int n;
int arr[100005];
int visit[100005];
int res[100005];
int num[100005];

void calc(int k) {
    memset(visit, 0, sizeof(visit));
    memset(num, 0, sizeof(num));

    int ans = 0;
    int pre = arr[k];
    num[ans] = pre;
    while (!visit[pre]) {
        visit[pre] = 1;
        ans++;
        pre = arr[pre];
        num[ans] = pre;
    }

    for (int i = 0; i < ans; i++)
        res[num[i]] = ans;
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &arr[i]);

    int ans = 1;
    for (int i = 1; i <= n; i++) {
        if (!res[i])
            calc(i);
        if (res[i] > ans)
            ans = res[i];
    }
    printf("%d\n", ans);
    return 0;
}
