//
// 1086 背包问题 V2
//

#include <bits/stdc++.h>
using namespace std;

int need[105];
int value[105];
int quanties[105];
int best[50005];

int main() {
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        cin >> need[i] >> value[i] >> quanties[i];

    for(int i = 1; i <= n; i++)
        for(int j = m; j >= need[i]; j--)
            for(int k = min(quanties[i], j / need[i]); k >= 0; k--)
                best[j] = max(best[j], best[j - k * need[i]] + value[i] * k);

    cout << best[m] << endl;
    return 0;
}
