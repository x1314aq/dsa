#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

static void fn(string &pre, string &in, string &post, int prel, int prer, int inl, int inr) {
    string::size_type i, j;

    if (inr - inl == 1) {
        post.push_back(in[inl]);
        return;
    }

    i = in.find(pre[prel]);
    if (i != inl) {
        j = pre.find(in[i - 1]);
        fn(pre, in, post, prel + 1, j + 1, inl, i);
    }
    if (i + 1 != inr) {
        fn(pre, in, post, prel + 1 + i - inl, prer, i + 1, inr);
    }
    post.push_back(in[i]);
}

int main() {
    string pre, in, post;
    int cur = 0;
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> in >> pre;

    fn(pre, in, post, 0, pre.length(), 0, in.length());

    cout << post << endl;
    return 0;
}