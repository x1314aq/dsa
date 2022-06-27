#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int arr[200005];

int main() {
    int n;
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    int f = arr[1], g = arr[1];
    for (int i = 2; i <= n; i++) {
        g = max(g + arr[i], arr[i]);
        f = max(f, g);
    }
    cout << f << endl;
    return 0;
}
