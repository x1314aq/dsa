//
// 2067 n皇后问题
//

#include <bits/stdc++.h>

using namespace std;

int col[10];
int n;
int ans = 0;

bool check(int k) {
    for (int i = 1; i < k; i++)
        if (col[i] == col[k] || abs(col[i] - col[k]) == abs(i - k))
            return false;
    return true;
}

void dfs(int k) {
    if (k == n + 1) {
        ans++;
        return;
    }

    for (int i = 1; i <= n; i++) {
        col[k] = i;
        if (check(k))
            dfs(k + 1);
    }
}

int main() {
	cin >> n;
	dfs(1);
	cout<< ans << endl;
	return 0;
}
