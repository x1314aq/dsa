//
// 51nod 1094 和为k的连续区间
//

#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pil = pair<int, ll>;

ll arr[10005];

bool cmp(const pil &a, const pil &b) {
    return a.second == b.second ? a.first < b.first : a.second < b.second;
}

bool cmp2(const pil &a, const ll v) {
    return a.second < v;
}

int main() {
    int n, k;
    vector<pil> vec;

    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        arr[i] += arr[i - 1];
        vec.push_back(make_pair(i, arr[i]));
    }

    sort(vec.begin(), vec.end(), cmp);
    bool found = false;
    for (int i = 0; i < n; i++) {
        ll key = arr[i] + k;
        auto it = lower_bound(vec.begin(), vec.end(), key, cmp2);
        if (it != vec.end() && it->second == key && it->first > i) {
            cout << i + 1 << " " << it->first << endl;
            found = true;
            break;
        }
    }

    if (!found)
        cout << "No Solution" << endl;
    return 0;
}
