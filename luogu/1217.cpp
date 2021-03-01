#include <bits/stdc++.h>

using namespace std;
using ll = long long int;

#define MAXN 10000005
int vis[MAXN];
int prime[MAXN];
bool pp[MAXN];

void prime_generator(int n) {
	int cnt = 0;
	for(int i = 2; i <= n; i++) {
        if(!vis[i]) prime[cnt++] = i, pp[i] = true;
        for(int j = 0;j < cnt && i * prime[j] <= n; j++) {
            vis[i * prime[j]] = i;
            if(i % prime[j] == 0) break;
        }
    }
}

bool palindrome(int n) {
    int x = n, num = 0;
    while (x) {
        num = num * 10 + x % 10;
        x /= 10;
    }
    return num == n;
}

int main() {
    int n, m;
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    if (m > 10000000) m = 10000000;
    prime_generator(m);
    for (int i = n; i <= m; ++i) {
        if (pp[i] && palindrome(i))
            cout << i << endl;
    }

    return 0;
}
