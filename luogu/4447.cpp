#include <bits/stdc++.h>

using namespace std;
using ll = long long int;
using pii = pair<int, int>;
using pil = pair<int, ll>;
using pll = pair<ll, ll>;

int n;
int a[100005];
pii v[100005];
int cnt;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a, a + n);
    bool flag = true;
    for (int i = 0; i < n; i++) {
        for (int j = cnt - 1; j >= 0; j--) {
            if (v[j].first + 1 == a[i]) {
                v[j].first = a[i];
                v[j].second++;
                flag = false;
                break;
            }
            else {
                flag = true;
            }
        }
        if (flag) {
            v[cnt++] = make_pair(a[i], 1);
        }
    }
    int ans = n;
    for (int i = 0; i < cnt; ++i) {
        ans = min(ans, v[i].second);
    }
    cout << ans << endl;
    return 0;
}
