/**
 * hihoCoder 1515  分数调查
 * 带权并查集
 */

#include <vector>
#include <iostream>
#include <algorithm>
#include <functional>
#include <cstdio>
#include <cstring>
#include <cstdlib>

using namespace std;

typedef pair<int, int> pii;

int sets[100005];
int credits[100005];

static void init(int n) {
    for(int i = 1; i <= n; i++)
        sets[i] = i;
}

static int find(int x) {
    if(sets[x] == x)
        return x;
    int tmp = sets[x];
    sets[x] = find(sets[x]);
    credits[x] += credits[tmp];
    return sets[x];
}

static void join(int x, int y, int s) {
    int fx = find(x);
    int fy = find(y);
    if(fx != fy) {
        sets[fx] = fy;
        credits[fx] = credits[y] + s - credits[x];
    }
}

int main() {
    int n, m, q;

    scanf("%d %d %d", &n, &m, &q);
    init(n);
    for(int i = 1; i <= m; i++) {
        int x, y, s;
        scanf("%d %d %d", &x, &y, &s);
        join(x, y, s);
    }

    vector<int> ans;
    for(int i = 1; i <= q; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        int fx = find(x);
        int fy = find(y);
        if(fx != fy)
            ans.push_back(-1);
        else
            ans.push_back(credits[x] - credits[y]);
    }

    for(int i = 0; i < q; i++)
        printf("%d\n", ans[i]);
    return 0;
}
