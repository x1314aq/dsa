#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

static int g_sup[100005];
static bool g_prime[100005];

static int find(int x) {
    int sup = g_sup[x] == x ? x : find(g_sup[x]);
    g_sup[x] = sup;
    return sup;
}

static void join(int x, int y) {
    int fx = find(x);
    int fy = find(y);

    g_sup[fy] = fx;
}

static void prime(int b) {
    int k = sqrt(b);
    for (int i = 0; i <= b; i++) {
        g_prime[i] = true;
    }
    for (int i = 2; i <= k; i++) {
        if (g_prime[i]) {
            for (int j = 2; i * j <= b; j++) {
                g_prime[i * j] = false;
            }
        }
    }
}

int main() {
    int a, b, p, n = 0;
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> a >> b >> p;
    for (int i = 1; i <= b; i++) {
        g_sup[i] = i;
    }
    prime(b);
    for (int i = p; i <= b; i++) {
        if (g_prime[i]) {
            int j = 0;
            while (i * j < a) j++;
            int u = i * j;
            for (; i * j <= b; j++) {
                join(u, i * j);
            }
        }
    }
    for (int i = a; i <= b; i++) {
        if (g_sup[i] == i) {
            n++;
        }
    }
    cout << n << endl;
    return 0;
}