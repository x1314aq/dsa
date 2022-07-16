#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

ll c1[50005];
ll c2[50005];
int n;
constexpr int nn = 50000;
pii arr[50005];

static int lowbit(int x) {
    return x & (-x);
}

static ll query_cnt(int x) {
    ll ans = 0;
    while (x) {
        ans += c1[x];
        x -= lowbit(x);
    }
    return ans;
}

static void update_cnt(int x, int k) {
    while (x <= nn) {
        c1[x] += k;
        x += lowbit(x);
    }
}

static ll query_sum(int x) {
    ll ans = 0;
    while (x) {
        ans += c2[x];
        x -= lowbit(x);
    }
    return ans;
}

static void update_sum(int x, int k) {
    while (x <= nn) {
        c2[x] += k;
        x += lowbit(x);
    }
}

static bool cmp(const pii &a, const pii &b) {
    return a.first < b.first;
}

int main() {
    ll ans = 0, t = 0;
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i].first >> arr[i].second;
    }
    sort(arr + 1, arr + n + 1, cmp);
    for (int i = 1; i <= n; i++) {
        ll cnt = query_cnt(arr[i].second);
        ll sum = query_sum(arr[i].second);
        ans += (arr[i].second * cnt - sum) * arr[i].first;
        ans += ((t - sum) - (i - 1 - cnt) * arr[i].second) * arr[i].first;
        t += arr[i].second;
        update_cnt(arr[i].second, 1);
        update_sum(arr[i].second, arr[i].second);
    }
    cout << ans << endl;
    return 0;
}
