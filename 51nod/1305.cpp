//
// 1305 Pairwise Sum and Divide
//

#include <bits/stdc++.h>

using namespace std;

int arr[100005];

int main() {
    int n;
    int a = 0, b = 0;

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        if (arr[i] == 1)
            a++;
        else if (arr[i] == 2)
            b++;
    }

    cout << (n - 1) * a + b * (b - 1) / 2 << endl;
    return 0;
}
