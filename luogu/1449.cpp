#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
    vector<ll> oprands;
    ll a = 0;
    ll u, v;

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    char c;
    do {
        cin >> c;

        switch (c) {
        default:
            break;
        case '0':
        case '1':
        case '2':
        case '3':
        case '4':
        case '5':
        case '6':
        case '7':
        case '8':
        case '9':
            a *= 10;
            a += (ll)(c - '0');
            break;
        case '.':
            oprands.push_back(a);
            a = 0;
            break;
        case '+':
            u = oprands.back();
            oprands.pop_back();
            v = oprands.back();
            oprands.pop_back();

            oprands.push_back(v + u);
            break;
        case '-':
            u = oprands.back();
            oprands.pop_back();
            v = oprands.back();
            oprands.pop_back();

            oprands.push_back(v - u);
            break;
        case '*':
            u = oprands.back();
            oprands.pop_back();
            v = oprands.back();
            oprands.pop_back();

            oprands.push_back(v * u);
            break;
        case '/':
            u = oprands.back();
            oprands.pop_back();
            v = oprands.back();
            oprands.pop_back();

            oprands.push_back(v / u);
            break;
        }
    } while (c != '@');

    cout << oprands.back() << endl;
    return 0;
}