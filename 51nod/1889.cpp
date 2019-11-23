//
// 1889 制铁棒
//

#include <bits/stdc++.h>

using namespace std;

int n, m;
vector<int> arr;

int fn() {
    int l = 0, r = 1e9;
    int sum = 0;
    int mid;

    while (l + 1 < r) {
        mid = (l + r) / 2;
        sum = 0;
        for (int i = 0; i < n; i++)
            sum += arr[i] / mid;
        if (sum >= m)
            l = mid;
        else
            r = mid;

    }
    return l;
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        double tmp;
        cin >> tmp;
        arr.push_back((int)(tmp * 100));
    }

    cout.flags(ios::fixed);
    cout.precision(2);
    cout << (double)fn() / 100 << endl;
    return 0;
}
