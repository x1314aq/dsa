//
// 1057 N的阶乘
//

#include <bits/stdc++.h>

using namespace std;
using ull = unsigned long long;

const ull mod = 1e14;
ull ans[1000005];

int main() {
    int n, ind;
    scanf("%d", &n);
    ans[0] = 1;
    ind = 1;

    ull carry;
    for(int i = 1; i <= n; i++) {
        carry = 0;
        for(int j = 0; j < ind; j++) {
            ull s = ans[j] * i + carry;
            carry = s / mod;
            ans[j] = s % mod;
        }
        if(carry)
            ans[ind++] = carry;
    }
    printf("%llu", ans[ind - 1]);
    for(int i = ind - 2; i >= 0; i--)
        printf("%014llu", ans[i]);
    printf("\n");

    return 0;
}
