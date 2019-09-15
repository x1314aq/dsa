/**
 * hihoCoder 1288  font size
 */


#include <bits/stdc++.h>
using namespace std;

int a[1005];
int n, p, w, h;

bool check(int x) {
    int res = 0;
    int tmp = w / x;
    for(int i = 1; i <= n; i++)
        res += ceil(1.0 * a[i] / tmp);
    tmp = ceil(1.0 * res / (h / x));
    return tmp > p;
}

int bsearch(int l, int r) {
    int mid;
    while(l < r) {
        mid = (l + r) / 2;
        if(check(mid))
            r = mid;
        else
            l = mid + 1;
    }
    return l - 1;
}

int main() {
    int m;
    scanf("%d", &m);
    vector<int> ans;
    for(int i = 1; i <= m; i++) {
        scanf("%d %d %d %d", &n, &p, &w, &h);
        for(int j = 1; j <= n; j++)
            scanf("%d", &a[j]);

        int lim = min(w, h);
        ans.push_back(bsearch(1, lim + 1));
    }
    for(int i = 0; i < m; i++)
        printf("%d\n", ans[i]);
    return 0;
}
