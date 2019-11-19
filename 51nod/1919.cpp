//
// 1919 炮兵阵地
//

#include <bits/stdc++.h>

using namespace std;

char s[5][5];
int ans;
int n;

void dfs(int x, int y, int cur) {
    ans = max(ans, cur);
    s[x][y] = 'X';
    int dx, ux, ly, ry;
    for(dx = x + 1; dx < n && s[dx][y] == '.'; ++dx)
        s[dx][y] = 'X';
    for(ux = x - 1; ux >= 0 && s[ux][y] == '.'; --ux)
        s[ux][y] = 'X';
    for(ry = y + 1; ry < n && s[x][ry] == '.'; ++ry)
        s[x][ry] = 'X';
    for(ly = y - 1; ly >= 0 && s[x][ly] == '.'; --ly)
        s[x][ly] = 'X';
    for(int i = x; i < n; ++i) {
        for(int j = (i == x ? y + 1 : 0); j < n; ++j) {
            if (s[i][j] == 'X')
                continue;
            dfs(i, j, cur + 1);
        }
    }
    for (int k = ux + 1; k < dx; ++k)
        s[k][y] = '.';
    for(int k = ly + 1; k < ry; ++k)
        s[x][k] = '.';
}

int main(void) {
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
        scanf("%s", s[i]);

    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            if (s[i][j] == 'X')
                continue;
            dfs(i, j, 1);
        }
    }
    printf ("%d\n", ans);
    return 0;
}
