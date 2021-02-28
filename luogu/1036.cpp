#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int n, k;
int a[5000005];
int ans;

bool isprime(ll a){
    for(ll i = 2; i * i <= a; i++)
        if(a % i == 0)
            return false;
    return true;
}

void fn(int i, ll sum, int startx) {
    if (i == k) {
        if (isprime(sum))
            ans++;
        return;
    }
    for (int j = startx; j < n; j++) {
        fn(i + 1, sum + a[j], j + 1);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n >> k;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    fn(0, 0, 0);
    cout << ans << endl;
    return 0;
}
