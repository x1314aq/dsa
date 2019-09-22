//
// 1027 大数乘法
//

#include <bits/stdc++.h>

using namespace std;
using ull = unsigned long long;

char a[1005];
char b[1005];
char ans[1000005];
char tmp[1000005];

void add_to(int len) {
    int ans_len = strlen(ans);
    int carry = 0, i;

    for(i = 0; i < max(ans_len, len); i++) {
        int sum = carry;
        if(i < len)
            sum += tmp[i] - '0';
        if(i < ans_len)
            sum += ans[i] - '0';
        ans[i] = sum % 10 + '0';
        carry = sum / 10;
    }
    if(carry)
        ans[i] = carry + '0';
}

int main() {
    int len_a, len_b, len;

    scanf("%s %s", a, b);
    len_a = strlen(a);
    len_b = strlen(b);

    for(int i = len_a - 1; i >= 0; i--) {
        memset(tmp, 0, sizeof(tmp));
        for(int j = 0; j < len_a - 1 - i; j++)
            tmp[j] = '0';

        int ind = len_a - 1 - i;
        int carry = 0;
        int c = a[i] - '0';
        for(int j = len_b - 1; j >= 0; j--) {
            int d = b[j] - '0';
            int product = c * d + carry;
            tmp[ind++] = (product % 10) + '0';
            carry = product / 10;
        }
        if(carry)
            tmp[ind++] = carry + '0';
        add_to(ind);
    }

    int ans_len = strlen(ans);
    for(int i = ans_len - 1; i >= 0; i--)
        printf("%c", ans[i]);
    printf("\n");
    return 0;
}
