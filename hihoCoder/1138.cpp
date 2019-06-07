/**
 * hihoCoder 1138 Islands Travel
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    vector<pair<int, int> > islands;

    cin >> n;
    for(int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        islands.push_back(make_pair(a, b));
    }


    return 0;
}
