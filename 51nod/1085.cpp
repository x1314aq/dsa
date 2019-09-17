//
// 1085 背包问题
//

#include <bits/stdc++.h>
using namespace std;

int need[105];
int value[105];
int best[10005];

int main() {
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        cin >> need[i] >> value[i];

    for(int i = 1; i <= n; i++)
        for(int j = m; j >= need[i]; j--)
            best[j] = max(best[j], best[j - need[i]] + value[i]);

    cout << best[m] << endl;
    return 0;
}
