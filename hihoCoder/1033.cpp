/**
 * hihoCoder 1033  交错和
 * 数位DP
 * Reference https://www.cnblogs.com/pinganzi/p/6656847.html
 */


#include <bits/stdc++.h>
using namespace std;
typedef long long s64;
const s64 mod = 1000000007;

struct node {
    s64 sum;
    s64 num;
    node(): sum(0), num(-1) {}
    node(s64 a, s64 b): sum(a), num(b) {}
};

node dp[20][20][300];
int bits[20];
s64 base[20];

node dfs(int len, int dig, bool zero, bool limit, int k) {
    node t(0, 0);
    if(len <= 0 || len >= 20 || k < -100 || k > 100) return t;
    if(!limit && dp[len][dig + (zero ? 0 : 10)][k + 100].num != -1)
        return dp[len][dig + (zero ? 0 : 10)][k + 100];
    if(len == 1) {
        if(dig == k) return node(k, 1);
        return t;
    }
    int r = limit ? bits[len - 2] : 9;
    int new_k = dig - k;
    node temp;
    for(int i = 0; i <= r; i++) {
        if(zero)
            temp = dfs(len - 1, i, i == 0, limit && (i == r), k);
        else
            temp = dfs(len - 1, i, false, limit && (i == r), new_k);
        t.num += temp.num;
        t.sum = ((t.sum + temp.sum) % mod + ((temp.num * dig) % mod * base[len]) % mod) % mod;
    }
    if(!limit)
        dp[len][dig + (zero ? 0 : 10)][k + 100] = t;
    return t;
}

s64 solve(s64 n, int k) {
    int i = 0;
    for(i = 0; i < 20; i++)
        bits[i] = 0;
    i = 0;
    while(n) {
        bits[i++] = n % 10;
        n /= 10;
    }
    return dfs(i + 1, 0, true, true, k).sum;
}

int main() {
    s64 l, r;
    int k;
    cin >> l >> r >> k;

    base[1] = 1;
    for(int i = 2; i < 20; i++)
        base[i] = (base[i - 1] * 10) % mod;

    cout << (solve(r, k) - solve(l - 1, k) + mod) % mod << endl;
    return 0;
}
