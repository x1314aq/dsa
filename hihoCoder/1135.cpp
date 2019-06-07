/**
 * hihoCoder 1135 Magic Box
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>

using namespace std;

static bool vanish(int m, int n, int x, int y, int z, string &inp) {
    int cy = 0, cr = 0, cb = 0;
    for(int i = m; i < n; i++) {
        if(inp[i] == 'R')
            cr++;
        else if(inp[i] == 'Y')
            cy++;
        else
            cb++;
    }

    int a = cr - cy > 0 ? cr - cy : cy - cr;
    int b = cr - cb > 0 ? cr - cb : cb - cr;
    int c = cb - cy > 0 ? cb - cy : cy - cb;
    if(a == x) {
        if(b == y) {
            if(c == z) return true;
        }
        else if(b == z) {
            if(c == y) return true;
        }
    }
    else if(a == y) {
        if(b == x) {
            if(c == z) return true;
        }
        else if(b == z) {
            if(c == x) return true;
        }
    }
    else if(a == z) {
        if(b == x) {
            if(c == y) return true;
        }
        else if(b == y) {
            if(c == x) return true;
        }
    }
    return false;
}

int main() {
    int x, y, z;
    string input;
    int maximum = 0;
    vector<int> a;
    int start = 0;

    cin >> x >> y >> z;
    cin >> input;
    a.resize(input.size());

    maximum = a[0] = 1;
    for(size_t i = 1; i < a.size(); i++) {
        if(vanish(start, i, x, y, z, input)) {
            a[i] = 1;
            start = i;
        }
        else a[i] = a[i - 1] + 1;
        if(a[i] > maximum)
            maximum = a[i];
    }

    cout << maximum << endl;
    return 0;
}
