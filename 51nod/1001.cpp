//
// 1001 数组中和等于K的数对
//

#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pll = pair<ll, ll>;

unordered_map<ll, int> dict;
vector<pll> vec;

bool cmp(const pll &a, const pll &b) {
    return a.first < b.first;
}

int main() {
    int N, K;
    scanf("%d %d", &K, &N);
    for (int i = 0; i < N; i++) {
        ll tmp;
        scanf("%lld", &tmp);
        if (dict.find(K - tmp) != dict.end()) {
            ll a = min(tmp, K - tmp);
            ll b = max(tmp, K - tmp);
            vec.push_back(make_pair(a, b));
            dict.erase(K - tmp);
        } else {
            dict[tmp] = 1;
        }
    }

    if (vec.size()) {
        sort(vec.begin(), vec.end(), cmp);
        for (auto p : vec) {
            printf("%lld %lld\n", p.first, p.second);
        }
    } else
        printf("No Solution\n");
    return 0;
}
