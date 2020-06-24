//
// 1886 滑动窗口
//

#include <bits/stdc++.h>

using namespace std;

int a[1000005];
int p[1000005], q[1000005];
int n, k;

void cout_min() {
    int head = 0, tail = 0;
    for (int i = 0; i < n; i++) {
        while (head < tail && q[tail - 1] >= a[i]) tail--;
        q[tail] = a[i];
        p[tail++] = i;
        while (p[head] <= i - k) head++;
        if (i >= k - 1) cout << q[head] << ' ';
    }
    cout << endl;
}

void cout_max() {
    int head = 0, tail = 0;
    for (int i = 0; i < n; i++) {
        while (head < tail && q[tail - 1] <= a[i]) tail--;
        q[tail] = a[i];
        p[tail++] = i;
        while (p[head] <= i - k) head++;
        if (i >= k - 1) cout << q[head] << ' ';
    }
    cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n >> k;
    for (int i = 0; i < n; i++)
        cin >> a[i];

    cout_min();
    cout_max();
    return 0;
}
