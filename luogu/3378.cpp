//
// 3378 堆
//

#include <bits/stdc++.h>

using namespace std;

#define lc(x) (2 * (x) + 1)
#define rc(x) (2 * ((x) + 1))
#define pp(x) ((x) > 0 ? ((x)-1) / 2 : 0)

int arr[1000005];
int sz = 0;

void push(int x) {
    int u = sz;
    int p = pp(u);
    arr[sz++] = x;
    while (arr[u] < arr[p]) {
        int tmp = arr[p];
        arr[p] = arr[u];
        arr[u] = tmp;
        u = p;
        p = pp(u);
    }
}

static inline bool f(int u, int l, int r) {
    return (l < sz && arr[u] > arr[l]) || (r < sz && arr[u] > arr[r]);
}

void pop() {
    int u = 0;
    int l = lc(u);
    int r = rc(u);
    arr[0] = arr[--sz];
    while (f(u, l, r)) {
        int tmp = arr[u];
        if (l < sz && r >= sz) {
            arr[u] = arr[l];
            arr[l] = tmp;
            u = l;
        } else if (r < sz && l >= sz) {
            arr[u] = arr[r];
            arr[r] = tmp;
            u = r;
        } else {
            if (arr[l] < arr[r]) {
                arr[u] = arr[l];
                arr[l] = tmp;
                u = l;
            } else {
                arr[u] = arr[r];
                arr[r] = tmp;
                u = r;
            }
        }
        l = lc(u);
        r = rc(u);
    }
}

int main() {
    int n;
    ios::sync_with_stdio(false);

    cin >> n;
    for (int i = 0; i < n; i++) {
        int op, a;
        cin >> op;
        switch (op) {
        case 1:
            cin >> a;
            push(a);
            break;
        case 2:
            cout << arr[0] << endl;
            break;
        case 3:
            pop();
        default:
            break;
        }
    }
    return 0;
}
