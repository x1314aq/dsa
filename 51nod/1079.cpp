//
// 1079 中国剩余定理
//

#include <bits/stdc++.h>

using namespace std;
using ull = unsigned long long;

struct node {
    int a, m, t;
    ull M;
};

node arr[15];

int main() {
    int n;

    cin >> n;
    ull p = 1;
    for (int i = 0; i < n; i++) {
        cin >> arr[i].m >> arr[i].a;
        p *= arr[i].m;
    }

    ull sum = 0;
    for (int i = 0; i < n; i++) {
        arr[i].M = p / arr[i].m;
        while (arr[i].M * arr[i].t % arr[i].m != 1) arr[i].t++;
        sum += arr[i].a * arr[i].t * arr[i].M;
    }

    cout << sum % p << endl;
    return 0;
}
