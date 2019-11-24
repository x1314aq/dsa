//
// 1014 X^2 MOD P
//

#include <bits/stdc++.h>

using namespace std;
using ull = unsigned long long;

int main() {
    vector<ull> ans;
    ull p, a;

    cin >> p >> a;
    for (ull x = 1; x <= p; x++) {
        ull tmp = x * x;
        if (tmp % p == a)
            ans.push_back(x);
    }

    if (ans.size() == 0)
        cout << "No Solution" << endl;
    else {
        for (int i = 0; i < ans.size(); i++)
            cout << ans[i] << ' ';
        cout << endl;
    }
    return 0;
}
