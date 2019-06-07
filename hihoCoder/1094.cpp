/**
 * hihoCoder 1094 Lost in the City
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>

using namespace std;

char city[205][205];
char north[3][5];
char south[3][5];
char west[3][5];
char east[3][5];

bool equal(int i, int j, char a[3][5]) {
    for(int n = 0; n < 3; n++) {
        for(int m = 0; m < 3; m++) {
            if(city[i - 1 + n][j - 1 + m] != a[n][m])
                return false;
        }
    }
    return true;
}

bool itis(int i, int j) {
    if(equal(i, j, north))
        return true;
    if(equal(i, j, south))
        return true;
    if(equal(i, j, east))
        return true;
    if(equal(i, j, west))
        return true;
    return false;
}

int main() {
    int n, m;
    vector<pair<int, int>> res;

    scanf("%d %d", &n, &m);
    for(int i = 1; i <= n; i++) {
        scanf("%s", &city[i][1]);
    }

    for(int i = 0; i < 3; i++) {
        scanf("%s", north[i]);
    }

    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            west[i][j] = north[j][2 - i];
        }
    }

    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            south[i][j] = north[2 - i][2 - j];
        }
    }

    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            east[i][j] = west[2 - i][2 - j];
        }
    }

    for(int i = 2; i < n; i++) {
        for(int j = 2; j < m; j++) {
            if(itis(i, j))
                res.push_back(make_pair(i, j));
        }
    }

    for(size_t i = 0; i < res.size(); i++)
        printf("%d %d\n", res[i].first, res[i].second);
    return 0;
}
