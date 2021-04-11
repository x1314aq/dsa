#include <bits/stdc++.h>

using namespace std;
using ll = long long int;
using pii = pair<int, int>;
using pil = pair<int, ll>;
using pll = pair<ll, ll>;

string s;
int k;

int main() {
    string ans;
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> s >> k;
    int n = s.length();
    int l = 0, r = k + 1;
    for (int i = 0; i < n - k; ++i) {
        int u = s[l], v = l;
        for (int j = l; j < r; j++) {
            if (s[j] < u) {
                u = s[j];
                v = j;
            }
        }
        ans.push_back(u);
        l = v + 1;
        r++;
    }

    int i;
    for (i = 0; i < n - k; i++) {
        if (ans[i] != '0')
            break;
    }
    if (i == n - k)
        cout << '0' << endl;
    else
        cout << ans.substr(i) << endl;
    return 0;
}
