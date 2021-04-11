//
// 51nod 1089 最长回文子串 V2
//

#include <bits/stdc++.h>

using namespace std;
using ull = unsigned long long;

char s[100005];
int p[200005];

inline bool f(int a, int b) {
    char c = a & 1 ? '#' : s[a / 2];
    char d = b & 1 ? '#' : s[b / 2];
    return c == d;
}

int main() {
    scanf("%s", &s[1]);
    int len = 2 * strlen(&s[1]) + 1;
    int c = 1, r = 0, rad, tmp = 0;
    for (int i = 1; i <= len; i++) {
        if (i <= r)
            rad = min(p[2 * c - i], r - i);
        else
            rad = 0;
        while (i + rad <= len && i - rad >= 1 && f(i + rad, i - rad))
            rad++;
        p[i] = rad;
        if (i + rad - 1 > r) {
            c = i;
            r = i + rad - 1;
        }
        if (rad > tmp)
            tmp = rad;
    }
    printf("%d\n", tmp - 1);
    return 0;
}
