#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int main() {
    int n, m;
    int num = 0, base = 1;
    int map[256];
    string s;
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    map['0'] = 0;
    map['1'] = 1;
    map['2'] = 2;
    map['3'] = 3;
    map['4'] = 4;
    map['5'] = 5;
    map['6'] = 6;
    map['7'] = 7;
    map['8'] = 8;
    map['9'] = 9;
    map['A'] = 10;
    map['B'] = 11;
    map['C'] = 12;
    map['D'] = 13;
    map['E'] = 14;
    map['F'] = 15;

    map[0] = '0';
    map[1] = '1';
    map[2] = '2';
    map[3] = '3';
    map[4] = '4';
    map[5] = '5';
    map[6] = '6';
    map[7] = '7';
    map[8] = '8';
    map[9] = '9';
    map[10] = 'A';
    map[11] = 'B';
    map[12] = 'C';
    map[13] = 'D';
    map[14] = 'E';
    map[15] = 'F';

    cin >> n >> s >> m;
    reverse(s.begin(), s.end());
    for (int i = 0 ; i < s.length(); i++) {
        num += map[s[i]] * base;
        base *= n;
    }

    s.clear();
    while (num) {
        s.push_back(map[num % m]);
        num /= m;
    }
    reverse(s.begin(), s.end());
    cout << s << endl;
    return 0;
}