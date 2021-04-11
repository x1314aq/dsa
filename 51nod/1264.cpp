//
// 1264 线段相交
//

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

struct node {
    int x, y;
};

int cross(node base, node p1, node p2) {
    p1.x = p1.x - base.x;
    p1.y = p1.y - base.y;
    p2.x = p2.x - base.x;
    p2.y = p2.y - base.y;
    ll cros = (ll)p1.x * p2.y - (ll)p1.y * p2.x;
    if (cros == 0)
        return 0;
    else
        return cros > 0 ? 1 : -1;
}

int main(int argc, char **argv) {
    int T;
    node p1, p2, p3, p4;

    scanf("%d", &T);
    while (T--) {
        scanf("%d %d %d %d %d %d %d %d", &p1.x, &p1.y, &p2.x, &p2.y, &p3.x, &p3.y, &p4.x, &p4.y);
        if (cross(p1, p2, p3) * cross(p1, p2, p4) <= 0 && cross(p3, p4, p2) * cross(p3, p4, p1) <= 0)
            printf("Yes\n");
        else
            printf("No\n");
    }

    return 0;
}
