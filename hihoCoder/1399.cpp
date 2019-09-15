/**
 * hihoCoder 1399  shortening Sequence
 */


#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;

    vector<int> v;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
        int tmp;
        scanf("%d", &tmp);

        if(!v.size()) {
            v.push_back(tmp);
            continue;
        }

        int a = v.back();
        if((a + tmp) & 1)
            v.pop_back();
        else
            v.push_back(tmp);
    }

    printf("%zu\n", v.size());
    return 0;
}
