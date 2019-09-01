/**
 * hihoCoder 1174 拓扑排序一
 */

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

struct vertex {
    vector<int> deps;

    void append(int v) {
        deps.push_back(v);
    }
};

vertex vs[100005];
int visited[100005];

static void reset() {
    for(int i = 0; i < 100005; i++) {
        vs[i].deps.clear();
        visited[i] = 0;
    }
}

static bool _tsort(int v) {
    int n;

    visited[v] = 1;
    n = vs[v].deps.size();
    for(int i = 0; i < n; i++) {
        int u = vs[v].deps[i];
        switch(visited[u]) {
            case 0:
                if(!_tsort(u))
                    return false;
                break;
            case 1:
                return false;
            default:
                break;
        }
    }
    visited[v] = 2;
    return true;
}

static bool tsort(int n) {
    for(int i = 1; i <= n; i++) {
        if(!visited[i]) {
            if(!_tsort(i))
                return false;
        }
    }
    return true;
}

int main() {
    int total;
    bool ans[7];

    scanf("%d", &total);
    for(int i = 1; i <= total; i++) {
        int n, m;
        scanf("%d %d", &n, &m);
        for(int j = 1; j <= m; j++) {
            int a, b;
            scanf("%d %d", &a, &b);
            vs[b].append(a);
        }
        ans[i] = tsort(n);
        reset();
    }

    for(int i = 1; i <= total; i++)
        printf("%s\n", ans[i] ? "Correct" : "Wrong");
    return 0;
}
