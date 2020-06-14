//
// 5788 单调栈
//

#include <bits/stdc++.h>

using namespace std;

int ans[3000005];
int a[3000005];
int s[3000005];

int main() {
    int n;
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    int top = 0;
    for (int i = n; i >= 1; i--) {
        while (top && a[s[top]] <= a[i]) top--;
        ans[i] = s[top];
        s[++top] = i;
    }

    for (int i = 1; i <= n; i++)
        cout << ans[i] << ' ';
    cout << endl;
    return 0;
}
