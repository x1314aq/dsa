#include <bits/stdc++.h>

using namespace std;

struct node {
    struct node *prev;
    struct node *next;
    int number;
    bool deleted;

    node() {
        prev = nullptr;
        next = nullptr;
        number = 0;
        deleted = false;
    }
};

static inline void add_before(node *cur, node *n) {
    cur->prev->next = n;
    n->prev = cur->prev;
    cur->prev = n;
    n->next = cur;
}

static inline void add_after(node *cur, node *n) {
    cur->next->prev = n;
    n->next = cur->next;
    cur->next = n;
    n->prev = cur;
}

node g_a[100005];

int main() {
    int n, m;
    node head, tail;

    head.next = &g_a[0];
    g_a[1].number = 1;
    g_a[1].prev = &head;
    g_a[1].next = &tail;
    tail.prev = &g_a[0];

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i = 2; i <= n; i++) {
        int k, p;
        cin >> k >> p;
        g_a[i].number = i;
        if (p == 0) {
            add_before(&g_a[k], &g_a[i]);
        } else {
            add_after(&g_a[k], &g_a[i]);
        }
    }

    cin >> m;
    for (int i = 0; i < m; i++) {
        int k;
        cin >> k;
        g_a[k].deleted = true;
    }

    for (node *n = head.next; n != &tail; n = n->next) {
        if (!n->deleted) {
            cout << n->number << ' ';
        }
    }
    cout << endl;

    return 0;
}