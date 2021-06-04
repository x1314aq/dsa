#include <bits/stdc++.h>

using namespace std;
using ll = long long int;
using pii = pair<int, int>;
using pil = pair<int, ll>;
using pll = pair<ll, ll>;

int n, length, use[25];
string str[25];

static int canlink(string str1, string str2) {
    for (int i = 1; i < min(str1.length(), str2.length()); i++) {
        bool flag = true;
        for (int j = 0; j < i; j++)
            if (str1[str1.length() - i + j] != str2[j])
                flag = false;
        if (flag)
            return i;
    }
    return 0;
}

static void solve(string strnow, int lengthnow) {
    length = max(lengthnow, length);
    for (int i = 0; i < n; i++) {
        if (use[i] >= 2)
            continue;
        int c = canlink(strnow, str[i]);
        if (c > 0) {
            use[i]++;
            solve(str[i], lengthnow + str[i].length() - c);
            use[i]--;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 0; i <= n; ++i) {
        cin >> str[i];
    }
    solve(' ' + str[n], 1);
    cout << length << endl;
    return 0;
}
