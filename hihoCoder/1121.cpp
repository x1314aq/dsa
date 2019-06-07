/**
 * hihoCoder 1121 二分图一·二分图判定
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>

using namespace std;

enum {
    NONE = 0,
    WHITE = 1,
    BLACK = 2
};

class people{
public:
    int color;
    vector<int> neigh;

    people(): color(NONE), neigh() {}
    void reset() {
        color = NONE;
        neigh.clear();
    }

    void append(int a) {
        neigh.push_back(a);
    }
};

people vertex[10005];

static inline void mzero() {
    for(int i = 0; i < 10005; i++)
        vertex[i].reset();
}

static int bfs(int n) {
    queue<int> q;
    int i;

    for(i = 1; i <= n; i++) {
        if(!vertex[i].neigh.empty())
            break;
    }

    q.push(i);
    vertex[i].color = WHITE;

    while(!q.empty()) {
        int p = q.front();
        q.pop();
        for(size_t j = 0; j < vertex[p].neigh.size(); j++) {
            int x = vertex[p].neigh[j];
            if(vertex[x].color == NONE) {
                q.push(x);
                vertex[x].color = (vertex[p].color == WHITE ? BLACK : WHITE);
            }
            else if(vertex[x].color == vertex[p].color)
                return 0;
        }
    }

    return 1;
}

int main() {
    int t;
    vector<string> res;

    cin >> t;
    for(int i = 0; i < t; i++) {
        int n, m;
        cin >> n >> m;
        mzero();

        for(int j = 0; j < m; j++) {
            int u, v;
            cin >> u >> v;
            vertex[u].append(v);
            vertex[v].append(u);
        }

        res.push_back(bfs(n) == 1 ? "Correct" : "Wrong");
    }

    for(size_t i = 0; i < res.size(); i++)
        cout << res[i] << endl;

    return 0;
}
