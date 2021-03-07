#include <bits/stdc++.h>

using namespace std;
using ll = long long int;

string stradd(string &a, string &b) {
    string c;
    size_t lena = a.length();
    size_t lenb = b.length();

    int carry = 0;
    for (size_t i = 0; i < min(lena, lenb); ++i) {
        int n = a[i] - '0' + b[i] - '0' + carry;
        c.push_back(n % 10 + '0');
        carry = n / 10;
    }
    for (size_t i = min(lena, lenb); i < lena; i++) {
        int n = a[i] - '0' + carry;
        c.push_back(n % 10 + '0');
        carry = n / 10;
    }
    for (size_t i = min(lena, lenb); i < lenb; i++) {
        int n = b[i] - '0' + carry;
        c.push_back(n % 10 + '0');
        carry = n / 10;
    }
    if (carry)
        c.push_back(carry + '0');

    return c;
}

int main() {
    int m, n;
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> m >> n;
    string a("1"), b("1");
    for (int i = 2; i < n - m + 1; i++) {
        string p = stradd(a, b);
        a = b;
        b = p;
    }

    reverse(b.begin(), b.end());
    cout << b << endl;
    return 0;
}
