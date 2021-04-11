/**
 * hihoCoder 1032  最长回文子串
 * Manacher's Algorithm
 * See https://www.hackerrank.com/topics/manachers-algorithm
 */

#include <bits/stdc++.h>
using namespace std;

/*
int calc(string &s) {
    if (1 == s.size()) return 1;
    int i, a, b, mark, sz = s.size();
    int maxlen = 1;
    for (i = 0; i < sz && 2 * (sz - i) > maxlen;) {
        a = b = i;
        for (; b + 1 < sz && s[b] == s[b + 1]; ++b);
        i = b + 1; //the key step, rather than ++i, i could skip duplicate characters.
        for (; a > 0 && b + 1 < sz && s[a - 1] == s[b + 1]; --a, ++b);
        if (b - a + 1 > maxlen) {
            mark = a;
            maxlen = b - a + 1;
        }
    }
    return maxlen;
}
*/

int center(string &s, int l, int r) {
    int sz = s.size();
    while (l >= 0 && r < sz && s[l] == s[r]) {
        l--;
        r++;
    }
    return r - l - 1;
}

int calc(string &s) {
    int sz = s.size();
    if (sz == 1)
        return 1;
    int max_len = 1;
    for (int i = 0; i < sz; i++) {
        int len1 = center(s, i, i);
        int len2 = center(s, i, i + 1);
        int len = max(len1, len2);
        if (len > max_len)
            max_len = len;
    }
    return max_len;
}

int main() {
    int n;
    int res[35];
    cin >> n;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        res[i] = calc(s);
    }

    for (int i = 0; i < n; i++)
        cout << res[i] << endl;
    return 0;
}
