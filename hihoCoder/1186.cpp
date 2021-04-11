/**
 * hihoCoder 1186 Coordinates
 */

#include <bits/stdc++.h>
using namespace std;

int main() {
    int p, q, t;
    cin >> p >> q;

    vector<int> a;
    a.push_back(1);
    t = (int)sqrt(p);
    for (int i = 2; i <= t; i++) {
        if (p % i == 0) {
            a.push_back(i);
        }
    }
    size_t temp = a.size();
    a.resize(2 * temp);
    for (size_t i = temp; i < 2 * temp; i++) {
        a[i] = p / a[2 * temp - 1 - i];
    }
    if (a[temp - 1] == a[temp])
        a.erase(a.begin() + temp);

    vector<int> b;
    b.push_back(1);
    t = (int)sqrt(q);
    for (int i = 2; i <= t; i++) {
        if (q % i == 0) {
            b.push_back(i);
        }
    }
    temp = b.size();
    b.resize(2 * temp);
    for (size_t i = temp; i < 2 * temp; i++) {
        b[i] = q / b[2 * temp - 1 - i];
    }
    if (b[temp - 1] == b[temp])
        b.erase(b.begin() + temp);

    for (size_t i = 0; i < a.size(); i++) {
        for (size_t j = 0; j < b.size(); j++)
            cout << a[i] << " " << b[j] << endl;
    }
    return 0;
}
