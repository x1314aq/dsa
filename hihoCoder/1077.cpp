/**
 * hihoCoder 1077 RMQ问题再临-线段树
 */

#include <bits/stdc++.h>
using namespace std;

int weight[1000005];
int segtree[4000005];
int n;

void build(int n, int l, int r) {
    if (l == r)
        segtree[n] = weight[l];
    else {
        int mid = (l + r) / 2;
        build(2 * n, l, mid);
        build(2 * n + 1, mid + 1, r);
        segtree[n] = min(segtree[2 * n], segtree[2 * n + 1]);
    }
}

static int query(int n, int l, int r, int tl, int tr) {
    if (l == tl && r == tr)
        return segtree[n];
    int mid = (tl + tr) / 2;
    if (l > mid)
        return query(2 * n + 1, l, r, mid + 1, tr);
    else if (r <= mid)
        return query(2 * n, l, r, tl, mid);
    else {
        int lval = query(2 * n, l, mid, tl, mid);
        int rval = query(2 * n + 1, mid + 1, r, mid + 1, tr);
        return min(lval, rval);
    }
}

static void update(int n, int l, int r, int i, int val) {
    if (l == r) {
        segtree[n] = val;
        return;
    }
    int mid = (l + r) / 2;
    if (i > mid)
        update(2 * n + 1, mid + 1, r, i, val);
    else
        update(2 * n, l, mid, i, val);
    segtree[n] = min(segtree[2 * n], segtree[2 * n + 1]);
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &weight[i]);

    build(1, 1, n);
    vector<int> res;
    int q;
    scanf("%d", &q);
    for (int i = 1; i <= q; i++) {
        int op, a, b;
        scanf("%d %d %d", &op, &a, &b);
        if (op == 0)
            res.push_back(query(1, a, b, 1, n));
        else
            update(1, 1, n, a, b);
    }

    for (int i = 0; i < res.size(); i++)
        printf("%d\n", res[i]);
    return 0;
}
