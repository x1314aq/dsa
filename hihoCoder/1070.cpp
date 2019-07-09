/**
 * hihoCoder 1070  RMQ问题再临
 * 这题似乎数据有问题，网上找的答案也全是WA
 */

#include <algorithm>
#include <cstdio>

using namespace std;

int weight[10005];
int res[10005];

int query(int l, int r) {
    int ans = weight[l];
    for(int i = l + 1; i <= r; i++) {
        if(weight[i] < ans)
            ans = weight[i];
    }
    return ans;
}

int main() {
    int n, q, tot = 0;

    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
        scanf("%d", &weight[i]);

    scanf("%d", &q);
    for(int i = 1; i <= q; i++) {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        if(a == 0) res[tot++] = query(b, c);
        else weight[b] = c;
    }

    for(int i = 0; i < tot; i++)
        printf("%d\n", res[i]);
    return 0;
}
