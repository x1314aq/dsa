#include <bits/stdc++.h>

#include <bits/stdc++.h>

using namespace std;
using ll = long long int;

int n;
ll b;
int a[20005];

int main() {
    ll s = 0;
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> b;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    make_heap(a, a + n);
    for (int i = 1; i <= n; i++) {
        s += a[0];
        if (s >= b) {
            cout << i << endl;
            break;
        }
        pop_heap(a, a + n + 1 - i);
    }
    return 0;
}