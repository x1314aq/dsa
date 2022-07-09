#include <bits/stdc++.h>

using namespace std;
using ll = long long;
char aa[1024], bb[1024];
char ans[1024], tmp[1024];

static size_t add(char *a, size_t na, char *b, size_t nb) {
    int c = 0;
    size_t n = 0;
    for (; n < min(na, nb); n++) {
        int s = a[n] - '0' + b[n] - '0' + c;
        a[n] = (s % 10) + '0';
        c = s / 10;
    }
    if (na < nb) {
        for (n = na; n < nb; n++) {
            int s = b[n] - '0' + c;
            a[n] = (s % 10) + '0';
            c = s / 10;
        }
    } else if (na > nb) {
        for (n = nb; n < na; n++) {
            int s = a[n] - '0' + c;
            a[n] = (s % 10) + '0';
            c = s / 10;
        }
    }
    if (c != 0) {
        a[n++] = c + '0';
    }
    return n;
}

static size_t multiply(char *a, size_t na, char *b, size_t nb) {
    size_t n = 0;
    memset(ans, 0, sizeof(ans));

    for (size_t i = 0; i < na; i++) {
        size_t ntmp = 0;
        memset(tmp, 0, sizeof(tmp));
        for (; ntmp < i; ntmp++) {
            tmp[ntmp] = '0';
        }
        int x = a[i] - '0';
        int c = 0;
        for (size_t j = 0; j < nb; j++) {
            int s = x * (b[j] - '0') + c;
            tmp[ntmp++] = (s % 10) + '0';
            c = s / 10;
        }
        if (c) {
            tmp[ntmp++] = c + '0';
        }
        n = add(ans, n, tmp, ntmp);
    }
    copy_n(ans, n, a);
    return n;
}

int main() {
    int n;
    scanf("%d", &n);
    int nn = n * log10(2) + 1;
    printf("%d\n", nn);
    size_t na = 1, nb = 1;
    aa[0] = '2';
    bb[0] = '1';
    while (n) {
        if (n & 1) {
            nb = multiply(bb, nb, aa, na);
            if (nb > 500) {
                nb = 500;
            }
        }
        na = multiply(aa, na, aa, na);
        if (na > 500) {
            na = 500;
        }
        n >>= 1;
    }
    bb[0] -= 1;
    if (nb < 500) {
        for (; nb < 500; nb++) {
            bb[nb] = '0';
        }
    }
    reverse(bb, bb + nb);
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 50; j++) {
            char c = bb[50 * i + j];
            putchar(c);
        }
        putchar('\n');
    }
    return 0;
}
