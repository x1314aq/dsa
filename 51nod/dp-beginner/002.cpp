//
// 循环数组最大子段和
//

#include <bits/stdc++.h>

using namespace std;

using ll = long long;

ll arr[50005];
int n;

ll fn1() {
    ll ans, tmp;

    ans = tmp = arr[1];
    for (int i = 2; i <= n; i++) {
        tmp = max(arr[i], arr[i] + tmp);
        ans = max(ans, tmp);
    }
    return ans;
}

ll fn2() {
    ll ans, tmp;

    ans = tmp = arr[1];
    for (int i = 2; i <= n; i++) {
        tmp = min(arr[i], arr[i] + tmp);
        ans = min(ans, tmp);
    }
    return ans;
}

int main() {
    ll sum = 0;

    cin >> n;
    for (int i = 1; i <= n; i++) {
        int tmp;

        cin >> tmp;
        sum += tmp;
        arr[i] = tmp;
    }

    cout << max(fn1(), sum - fn2()) << endl;
    return 0;
}
