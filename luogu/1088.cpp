#include <bits/stdc++.h>

using namespace std;

bool vis[10005];
int a[10005];
int n, m;
bool found;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    while (m--)
        next_permutation(a, a + n);
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
    putchar('\n');
    return 0;
}
