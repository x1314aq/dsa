//
// 2627 树的深度及子树大小
//

#include <bits/stdc++.h>

using namespace std;

struct node {
    vector<int> childs;
    int depth;
    int size;
};

node nodes[100005];
int n;

int dfs(int k) {
    if (nodes[k].childs.size() == 0) {
        nodes[k].size = 1;
        return 1;
    }

    int tmp = 0;
    for (int i = 0; i < nodes[k].childs.size(); i++) {
        int c = nodes[k].childs[i];
        nodes[c].depth = nodes[k].depth + 1;
        tmp += dfs(c);
    }
    nodes[k].size = tmp + 1;
    return tmp + 1;
}

int main() {
    cin >> n;
    for (int i = 1; i <= n - 1; i++) {
        int p, c;
        cin >> p >> c;
        nodes[p].childs.push_back(c);
    }
    nodes[1].depth = 1;
    nodes[1].size = dfs(1);

    for (int i = 1; i <= n; i++)
        cout << nodes[i].depth << ' ';
    cout << endl;
    for (int i = 1; i <= n; i++)
        cout << nodes[i].size << ' ';
    cout << endl;
    return 0;
}
