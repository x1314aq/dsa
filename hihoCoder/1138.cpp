/**
 * hihoCoder 1138 Islands Travel
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <functional>
#include <cstring>
#include <climits>

using namespace std;

#define INF 1000000005

struct vertex {
    int x, y;
    int id;
    int neigh[4];
};

vertex islands[100005];
bool visit[100005];
int dist[100005];

static bool cmp0(vertex &a, vertex &b) {
    return a.id < b.id;
}

static bool cmp1(vertex &a, vertex &b) {
    return a.x < b.x;
}

static bool cmp2(vertex &a, vertex &b) {
    return a.y < b.y;
}

static int calc(int i, int j) {
    int x = islands[i].x > islands[j].x ? islands[i].x - islands[j].x : islands[j].x - islands[i].x;
    int y = islands[i].y > islands[j].y ? islands[i].y - islands[j].y : islands[j].y - islands[i].y;
    return min(x, y);
}

int main() {
    int n;

    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> islands[i].x >> islands[i].y;
        islands[i].id = i;
        dist[i] = INF;
        visit[i] = false;
    }

    sort(islands + 1, islands + n + 1, cmp1);
    islands[1].neigh[0] = 0;
    int i = 1, j;
    while(i <= n) {
        j = i + 1;
        islands[j].neigh[0] = islands[i].id;
        islands[i].neigh[1] = j <= n ? islands[j].id : 0;
        i++;
    }

    sort(islands + 1, islands + n + 1, cmp2);
    islands[1].neigh[2] = 0;
    i = 1;
    while(i < n) {
        j = i + 1;
        islands[j].neigh[2] = islands[i].id;
        islands[i].neigh[3] = j <= n ? islands[j].id : 0;
        i++;
    }

    sort(islands + 1, islands + n + 1, cmp0);
    queue<int> q;
    int max_dist = calc(1, n);
    for(int i = 1; i <= n; i++) {
        int temp = calc(1, i);
        if(temp < max_dist) {
            dist[i] = temp;
            q.push(i);
            visit[i] = true;
        }
    }

    while(!q.empty()) {
        int v = q.front();
        visit[v] = false;
        q.pop();
        for(int i = 0; i < 4; i++) {
            int u = islands[v].neigh[i];
            int temp = calc(v, u) + dist[v];
            if(temp < max_dist) {
                if(temp < dist[u]) {
                    dist[u] = temp;
                    if(u == n)
                        max_dist = temp;
                    else {
                        if(!visit[u]) {
                            q.push(u);
                            visit[u] = true;
                        }
                    }
                }
            }
        }
    }

    cout << dist[n] << endl;
    return 0;
}

