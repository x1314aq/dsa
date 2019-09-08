/**
 * hihoCoder 1053  居民迁移
 * DFS
 */

#include <vector>
#include <iostream>
#include <algorithm>
#include <functional>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>

using namespace std;

struct village {
    int x, y;
};

village vs[100005];

bool cmp(const village &a, const village &b) {
    return a.x < b.x;
}

int num[100005][2];
int n, r;

static bool check(int x) {
    int sum = 0;

    memset(num, 0, sizeof(num));
    num[1][0] = vs[1].y;
    int i = 1, target = 1;
    while(i <= n && target <= n) {
        if(abs(vs[i].x - vs[target].x) > r) {
            if(target > i)
                return false;
            else
                target++;
        }
        else {
            if(num[target][1] + num[i][0] <= x) {
                num[target][1] += num[i][0];
                num[i][0] = 0;
                i++;
                num[i][0] = vs[i].y;
            }
            else {
                num[i][0] -= (x - num[target][1]);
                num[target][1] = x;
                target++;
            }
        }
    }
    for(int j = 1; j <= n; j++)
        if(num[j][0])
            return false;
    return true;
}

static int solve(int inf, int sup) {
    while(inf + 1 < sup) {
        int mid = (inf + sup) / 2;
        if(check(mid))
            sup = mid;
        else
            inf = mid;
    }
    return sup;
}

int main() {
    int t;
    vector<int> ans;

    scanf("%d", &t);
    while(t--) {
        int lim = 0;
        memset(vs, 0, sizeof(vs));
        scanf("%d %d", &n, &r);
        for(int i = 1; i <= n; i++) {
            scanf("%d %d", &vs[i].x, &vs[i].y);
            lim = max(lim, vs[i].y);
        }
        sort(vs + 1, vs + n + 1, cmp);
        ans.push_back(solve(0, lim));
    }

    for(int i = 0; i < ans.size(); i++)
        cout << ans[i] << endl;
    return 0;
}
