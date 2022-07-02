#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

string fn(string const &s, int l, int r) {
    string ans;
    int num = 0;
    int i = l;
    for (; i < r; i++) {
        if (!isdigit(s[i])) {
            break;
        }
        num *= 10;
        num += (int)(s[i] - '0');
    }
    int level = 0;
    for (; i < r;) {
        if (s[i] == '[') {
            int j;
            level++;
            for (j = i + 1; j < r; j++) {
                if (s[j] == '[') {
                    level++;
                } else if (s[j] == ']') {
                    level--;
                    if (level == 0) {
                        break;
                    }
                }
            }
            ans += fn(s, i + 1, j);
            i = j + 1;
        } else {
            ans.push_back(s[i]);
            i++;
        }
    }
    string ret(ans);
    for (int i = 1; i < num; i++) {
        ret += ans;
    }
    return ret;
}

int main() {
    string s, ans;
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> s;
    size_t len = s.length();
    int level = 0;
    for (int i = 0; i < len;) {
        if (s[i] == '[') {
            int j;
            level++;
            for (j = i + 1; j < len; j++) {
                if (s[j] == '[') {
                    level++;
                } else if (s[j] == ']') {
                    level--;
                    if (level == 0) {
                        break;
                    }
                }
            }
            ans += fn(s, i + 1, j);
            i = j + 1;
        } else {
            ans.push_back(s[i]);
            i++;
        }
    }
    cout << ans << endl;
    return 0;
}
