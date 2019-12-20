//
// 1062 序列中最大的数
//

#include <bits/stdc++.h>

using namespace std;

int arr[20][100005];

void calc(int up) {
    arr[0][1] = 1;

    for (int i = 2; i <= up; i += 2) {
        arr[0][i] = arr[0][i / 2];
        arr[0][i + 1] = arr[0][i] + arr[0][i / 2 + 1];
    }

    int b = (int)floor(log2((double)up));
    for (int j = 1; j <= b; j++)
        for (int i = 0; i + (1 << (j - 1)) - 1 <= up; i++)
            arr[j][i] = max(arr[j - 1][i], arr[j - 1][i + (1 << (j - 1))]);
}

int query(int r) {
    int p = (int)floor(log2((double)r));
    return max(arr[p][0], arr[p][r - (1 << p) + 1]);
}

int main() {
    int t, up = 1;
    int input[15] = {0};

    cin >> t;
    for (int i = 0; i < t; i++) {
        cin >> input[i];
        up = max(up, input[i]);
    }

    calc(up);

    for (int i = 0; i < t; i++)
        cout << query(input[i]) << endl;
    return 0;
}
