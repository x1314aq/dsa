#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    ios::sync_with_stdio(false);
    cin >> t;

    while (t--) {
        int a, b;
        cin >> a >> b;
        cout << min(min(a, b), (a + b) / 3) << endl;
    }
    return 0;
}
