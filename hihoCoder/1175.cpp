/**
 * hihoCoder 1175 拓扑排序·二
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int mod = 142857;

enum {
    UNDISCOVERED,
    DISCOVERED,
    VISITED
};

class vertex {
public:
    int state;
    unsigned long count;
    vector<int> out_degree;

    vertex(): state(UNDISCOVERED), count(0) {}

    void append_out(int a) {
        out_degree.push_back(a);
    }
};

vertex vs[100005];

static void tsort(int i, vector<int> &arr) {
    vs[i].state = DISCOVERED;
    for(size_t n = 0; n < vs[i].out_degree.size(); n++) {
        int next = vs[i].out_degree[n];
        if(vs[next].state == UNDISCOVERED)
            tsort(next, arr);
    }
    vs[i].state = VISITED;
    arr.push_back(i);
}

int main() {
    int n, m, k;

    cin >> n >> m >> k;
    for(int i = 0; i < k; i++) {
        int temp;
        cin >> temp;
        vs[temp].count++;
    }

    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        vs[u].append_out(v);
    }

    vector<int> arr;
    for(int i = 0; i < n; i++) {
        if(vs[i].state == UNDISCOVERED)
            tsort(i, arr);
    }

    unsigned long res = 0;
    while(!arr.empty()) {
        int i = arr.back();
        for(size_t n = 0; n < vs[i].out_degree.size(); n++) {
            int j = vs[i].out_degree[n];
            vs[j].count = (vs[j].count + vs[i].count) % mod;
        }
        res = (res + vs[i].count) % mod;
        arr.pop_back();
    }
    cout << res << endl;
    return 0;
}
