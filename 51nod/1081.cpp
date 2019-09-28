//
// 1081 子段求和
//

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll arr[50005];
ll tree[200005];
int N, Q;

void build(int n, int l, int r) {
    if(l == r) tree[n] = arr[l];
    else {
        int mid = (l + r) / 2;
        build(2 * n, l, mid);
        build(2 * n + 1, mid + 1, r);
        tree[n] = tree[2 * n] + tree[2 * n + 1];
    }
}

ll query(int n, int l, int r, int tl, int tr) {
    if(l == tl && r == tr) return tree[n];
    int mid = (tl + tr) / 2;
    if(l > mid)
        return query(2 * n + 1, l, r, mid + 1, tr);
    else if (r <= mid)
        return query(2 * n, l, r, tl, mid);
    else {
        ll lval = query(2 * n, l, mid, tl, mid);
        ll rval = query(2 * n + 1, mid + 1, r, mid + 1, tr);
        return lval + rval;
    }
}

int main() {
    freopen("in.txt", "r", stdin);
    scanf("%d", &N);
    for(int i = 1; i <= N; i++)
        scanf("%lld", &arr[i]);

    build(1, 1, N);

    scanf("%d", &Q);
    for(int i = 1; i <= Q; i++) {
        int start, len;
        scanf("%d %d", &start, &len);
        printf("%lld\n", query(1, start, start + len - 1, 1, N));
    }
    return 0;
}
