//
// 1090 3个数的和为0
//

#include <bits/stdc++.h>

using namespace std;

struct node {
    int first, second, third;
    
    node(int a, int b) {
        int dummy[3] = {a, b, 0 - a - b};

        sort(dummy, dummy + 3);
        first = dummy[0];
        second = dummy[1];
        third = dummy[2];
    }

    bool operator< (const node &a) const {
        return first != a.first ? first < a.first
            : (second != a.second ? second < a.second : third < a.third);
    }
};

int arr[1005];
set<node> ans;

int main() {
    int n;
    unordered_map<int, bool> dict;
    
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    for (int i = 0; i < n; i++) {
        int tmp = -arr[i];
        for (int j = 0; j < n; j++) {
            if (i == j) continue;
            if (dict.find(tmp - arr[j]) != dict.end())
                ans.insert(node(arr[i], arr[j]));
            else dict[arr[j]] = true;
        }
        dict.clear();
    }

    if (ans.size() == 0)
        cout << "No Solution" << endl;
    else {
        for (auto it = ans.begin(); it != ans.end(); ++it)
            cout << it->first << ' ' << it->second << ' ' << it->third << endl;
    }
    return 0;
}
