/**
 * hihoCoder 1051 补提交卡
 */


#include <bits/stdc++.h>
using namespace std;

int main() {
    int t, n ,m;
    cin >> t;
    for(int i = 0; i < t; i++) {
        int temp;
        vector<int> inp;
        int ans = 0;
        cin >> n >> m;
        inp.push_back(0);
        for(int j = 0; j < n; j++) {
            cin >> temp;
            inp.push_back(temp);
        }
        inp.push_back(101);
        if(m >= n)
            ans = 100;
        else {
            for(int j = 1; j <= n - m + 1; j++)
                ans = max(ans, inp[j + m] - inp[j - 1] - 1);
        }
        cout << ans << endl;
    }
    return 0;
}
