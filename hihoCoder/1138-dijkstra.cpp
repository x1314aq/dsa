/**
 * hihoCoder 1138 Islands Travel
 */

// TLE and MLE

#include <bits/stdc++.h>
using namespace std;

#define INF 1000000005
typedef pair<int, int> pii;

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
    for (int i = 1; i <= n; i++) {
        cin >> islands[i].x >> islands[i].y;
        islands[i].id = i;
        dist[i] = INF;
        visit[i] = false;
    }

    sort(islands + 1, islands + n + 1, cmp1);
    islands[1].neigh[0] = 0;
    int i = 1, j;
    while (i <= n) {
        j = i + 1;
        while (j <= n && islands[j].x == islands[i].x) {
            islands[j].neigh[0] = islands[i].neigh[0];
            j++;
        }
        if (j <= n) {
            islands[i].neigh[1] = islands[j].id;
            islands[j].neigh[0] = islands[i].id;
        }
        for (int k = i + 1; k < j; k++)
            islands[k].neigh[1] = islands[i].neigh[1];
        i = j;
    }

    sort(islands + 1, islands + n + 1, cmp2);
    islands[1].neigh[2] = 0;
    i = 1;
    while (i < n) {
        j = i + 1;
        while (j <= n && islands[j].y == islands[i].y) {
            islands[j].neigh[2] = islands[i].neigh[2];
            j++;
        }
        if (j <= n) {
            islands[i].neigh[3] = islands[j].id;
            islands[j].neigh[2] = islands[i].id;
        }
        for (int k = i + 1; k < j; k++)
            islands[k].neigh[3] = islands[i].neigh[3];
        i = j;
    }

    sort(islands + 1, islands + n + 1, cmp0);

    priority_queue<pii, vector<pii>, greater<pii>> pq;
    dist[1] = 0;
    for (int i = 1; i <= n; i++)
        pq.push(make_pair(i, dist[i]));

    visit[0] = true;
    while (!pq.empty()) {
        pii p = pq.top();
        pq.pop();
        int u = p.first;
        if (p.second > dist[u])
            continue;
        if (u == n)
            break;
        visit[u] = true;
        for (int i = 0; i < 4; i++) {
            int v = islands[u].neigh[i];
            if (!visit[v]) {
                int temp = calc(u, v) + dist[u];
                if (temp < dist[v])
                    dist[v] = temp;
                pq.push(make_pair(v, dist[v]));
            }
        }
    }

    cout << dist[n] << endl;
    return 0;
}
