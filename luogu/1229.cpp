#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int main() {
    string pre, post;
    ll n = 0;
    int len;
    bool rev;
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> pre >> post;
    len = pre.length();

    for (int i = 0; i < len - 1; i++) {
        for (int j = 0; j < len; j++) {
            if (pre[i] == post[j] && pre[i + 1] == post[j - 1]) {
                n++;
            }
        }
    }
    cout << (1 << n) << endl;
    return 0;
}