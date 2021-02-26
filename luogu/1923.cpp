#include <bits/stdc++.h>

using namespace std;

int a[5000005];
int n, k;

static int qsort(int l, int r) {
    int m = a[l];
    while (l < r) {
        while (l < r && m <= a[r]) r--;
        a[l] = a[r];
        while (l < r && m >= a[l]) l++;
        a[r] = a[l];
    }
    a[l] = m;
    return l;
}

static void solve(int l, int r) {
    int x = qsort(l, r);
    if (x == k) {
        cout << a[x] << endl;
        exit(0);
    }
    else if (k - 1 < x)
        solve(l, x - 1);
    else solve(x + 1, r);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> k;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    solve(0, n - 1);
    return 0;
}
