//
// 1091 线段的重叠
//

#include <bits/stdc++.h>

using namespace std;
using pii = pair<int, int>;

bool cmp(const pii &a, const pii &b) {
    return a.first == b.first ? a.second > b.second : a.first < b.first;
}

int main() {
    int n;
    vector<pii> vec;

    cin >> n;
    for (int i = 0; i < n; i++) {
        int s, e;

        cin >> s >> e;
        vec.push_back(make_pair(s, e));
    }

    sort(vec.begin(), vec.end(), cmp);
    int ans = 0;
    int far = vec[0].second;
    for (int i = 1; i < n; i++) {
        int tmp = vec[i].second < far ? vec[i].second - vec[i].first : far - vec[i].first;
        ans = max(ans, tmp);
        far = max(far, vec[i].second);
    }

    cout << ans << endl;
    return 0;
}
