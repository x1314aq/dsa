/**
 * hihoCoder 1043  完全背包
 * DP
 */

#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int need[505];
int value[505];
int best[100005];

int main() {
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        cin >> need[i] >> value[i];

    for(int i = 1; i <= n; i++)
        for(int j = need[i]; j <= m; j++)
            best[j] = max(best[j], best[j - need[i]] + value[i]);

    cout << best[m] << endl;
    return 0;
}
