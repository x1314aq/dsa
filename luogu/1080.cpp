#include <bits/stdc++.h>

using namespace std;
using ll = long long int;
using pii = pair<int, int>;
using pil = pair<int, ll>;
using pll = pair<ll, ll>;

int now[20010], sum[20010], ans[20010], add[20010];

struct Node {
    int a;
    int b;
    long long a_b;
} node[1010];

void times(int x) {
    memset(add, 0, sizeof(add));
    for (int i = 1; i <= ans[0]; i++) {
        ans[i] = ans[i] * x;
        add[i + 1] += ans[i] / 10;
        ans[i] %= 10;
    }
    for (int i = 1; i <= ans[0] + 4; i++) {
        ans[i] += add[i];
        if (ans[i] >= 10) {
            ans[i + 1] += ans[i] / 10;
            ans[i] %= 10;
        }
        if (ans[i] != 0) {
            ans[0] = max(ans[0], i);
        }
    }
    return;
}

int divition(int x) {
    memset(add, 0, sizeof(add));
    int q = 0;
    for (int i = ans[0]; i >= 1; i--) {
        q *= 10;
        q += ans[i];
        add[i] = q / x;
        if (add[0] == 0 && add[i] != 0) {
            add[0] = i;
        }
        q %= x;
    }
    return 0;
}

bool compare() {
    if (sum[0] == add[0]) {
        for (int i = add[0]; i >= 1; i--) {
            if (add[i] > sum[i])
                return 1;
            if (add[i] < sum[i])
                return 0;
        }
    }
    return add[0] > sum[0];
}

void cp() {
    memset(sum, 0, sizeof(sum));
    for (int i = add[0]; i >= 0; i--) {
        sum[i] = add[i];
    }
}

bool cmp(const Node &a, const Node &b) {
    return a.a_b < b.a_b;
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i <= n; i++) {
        cin >> node[i].a >> node[i].b;
        node[i].a_b = node[i].a * node[i].b;
    }
    sort(node + 1, node + n + 1, cmp);
    ans[0] = 1, ans[1] = 1;
    for (int i = 1; i <= n; i++) {
        times(node[i - 1].a);
        divition(node[i].b);
        if (compare()) {
            cp();
        }
    }
    for (int i = sum[0]; i >= 1; i--)
        cout << sum[i];
    cout.flush();
    return 0;
}
