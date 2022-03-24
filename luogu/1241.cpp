#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

static bool match(char a, char b) {
    if (a == '(' && b == ')')
        return true;
    if (a == '[' && b == ']')
        return true;
    return false;
}

int main() {
    string s;
    vector<int> v;
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> s;
    int n = s.length();
    for (int i = 0; i < n; i++) {
        char c = s[i];
        if (c == '(' || c == '[') {
            v.push_back(i);
        } else {
            if (v.empty() || !match(s[v.back()], c)) {
                s.insert(s.begin() + i, 1, c == ')' ? '(' : '[');
                i++;
                n++;
            } else {
                v.pop_back();
            }
        }
    }
    while (!v.empty()) {
        char c;
        int i = v.back();
        v.pop_back();
        if (s[i] == '(') {
            c = ')';
        } else {
            c = ']';
        }
        s.insert(s.begin() + i + 1, 1, c);
    }
    cout << s << endl;
    return 0;
}