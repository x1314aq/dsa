//
// 1203 [USACO1.1]坏掉的项链Broken Necklace
//

#include <bits/stdc++.h>

using namespace std;
int n;
string s;
int ans;

void fn(int a) {
    int tmp = 0;
    int i = 0;

    string s1 = s.substr(a) + s;
    s1.erase(n);
    string s2 = s1;
    reverse(s2.begin(), s2.end());

    while (s1[i] == 'w') tmp++, i++;
    for (int j = i; j < n; j++) {
        if (s1[i] == s1[j] || s1[j] == 'w') tmp++;
        else break;
    }
    i = 0;
    while (s2[i] == 'w') tmp++, i++;
    for (int j = i; j < n; j++) {
        if (s2[i] == s2[j] || s2[j] == 'w') tmp++;
        else break;
    }
    ans = max(ans, tmp);
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n >> s;
    for (int i = 0; i < n; i++)
        fn(i);
    cout << min(n, ans) << endl;
    return 0;
}
