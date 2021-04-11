#include <bits/stdc++.h>

using namespace std;
int a[1005];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int b;
        cin >> b;
        a[b]++;
    }
    for (int i = 1; i <= n; i++)
        while (a[i]--)
            cout << i << ' ';
    cout.flush();

    return 0;
}
