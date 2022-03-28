#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

static void fn(string &pre, string &in, string &post, int inl, int inr, int postl, int postr) {
    string::size_type i, j;

    if (inr - inl == 1) {
        pre.push_back(in[inl]);
        return;
    }

    pre.push_back(post[postr - 1]);
    i = in.find(post[postr - 1]);
    if (i != inl) {
        fn(pre, in, post, inl, i, postl, postl + i - inl);
    }
    if (i + 1 != inr) {
        fn(pre, in, post, i + 1, inr, postl + i - inl, postr - 1);
    }
}

int main() {
    string pre, in, post;
    int cur = 0;
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> in >> post;

    fn(pre, in, post, 0, in.length(), 0, post.length());

    cout << pre << endl;
    return 0;
}