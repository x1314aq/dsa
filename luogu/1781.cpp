#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, id;
    string max;
    string in;
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> in;
        int a = in.size();
        int b = max.size();
        if (a > b || (a >= b && in > max)) {
            id = i;
            max = in;
        }
    }
    cout << id << endl << max << endl;
    return 0;
}