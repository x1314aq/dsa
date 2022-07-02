#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

char arr[1000];
int y;

void move(int k) {
    arr[y] = arr[k];
    arr[y + 1] = arr[k + 1];
    arr[k] = arr[k + 1] = '-';
    y = k;
    cout << arr;
}

void mv(int x) {
    if (x == 4) {
        move(3);
        move(7);
        move(1);
        move(6);
        move(0);
    } else {
        move(x - 1);
        move(2 * (x - 1));
        mv(x - 1);
    }
}

int main() {
    int n;
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 0; i < n; i++) {
        arr[i] = 'o';
    }
    for (int i = n; i < 2 * n; i++) {
        arr[i] = '*';
    }
    arr[2 * n] = arr[2 * n + 1] = '-';
    arr[2 * n + 2] = '\n';
    cout << arr;
    y = 2 * n;
    mv(n);
    cout.flush();
    return 0;
}
