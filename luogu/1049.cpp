//
// 1049 装箱问题
//

#include <bits/stdc++.h>

using namespace std;
int V, N;
int v[35];
int dp[20005];

int main() {
    ios::sync_with_stdio(false);
    cin >> V >> N;
    for (int i = 1; i <= N; i++)
        cin >> v[i];

    for (int i = 1; i <= N; i++)
        for (int j = V; j >= v[i]; j--)
            dp[j] = max(dp[j], dp[j - v[i]] + v[i]);

    cout << V - dp[V] << endl;
    return 0;
}
