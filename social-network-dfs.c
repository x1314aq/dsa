#include <stdio.h>

char mat[301][301];
int prev[301], stk[301], it_stk;

int treeFind(int n) {
    if (prev[n] == n)
        return n;
    it_stk = 0;
    while (prev[n] != n) {
        stk[it_stk++] = n;
        n = prev[n];
    }
    stk[it_stk] = n;
    while (it_stk--)
        prev[stk[it_stk]] = prev[stk[it_stk + 1]];
    return prev[*stk];
}

void treeUnion(int a, int b) {
    int a_f = treeFind(a), b_f = treeFind(b);
    if (a_f != b_f) prev[a_f] = prev[b_f];
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%s", mat[i]);
        prev[i] = i;
    }
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < i; ++j)
            if (mat[i][j] == '1') treeUnion(i, j);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j)
            putchar((i == j || treeFind(i) == treeFind(j)) ? '1' : '0');
        putchar('\n');
    }
    return 0;
}

