/**
 * Leetcode 23 Merge k Sorted Lists
 * priority queue
 */

#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

struct cmp {
    bool operator()(ListNode *a, ListNode *b) { return a->val > b->val; }
};

class Solution {
  public:
    priority_queue<ListNode *, vector<ListNode *>, cmp> pq;

    ListNode *mergeKLists(vector<ListNode *> &lists) {
        size_t num = lists.size();
        if (num == 0)
            return NULL;
        ListNode head(0);

        for (size_t i = 0; i < num; i++) {
            if (lists[i])
                pq.push(lists[i]);
        }

        ListNode *cur = &head;
        while (!pq.empty()) {
            ListNode *temp = pq.top();
            pq.pop();
            cur->next = temp;
            if (temp->next)
                pq.push(temp->next);
            cur = temp;
        }
        cur->next = NULL;

        return head.next;
    }
};

int main() {
    ListNode h1(1);
    ListNode q(4);
    ListNode w(5);
    h1.next = &q;
    q.next = &w;

    ListNode h2(1);
    ListNode a(3);
    ListNode s(4);
    h2.next = &a;
    a.next = &s;

    ListNode h3(2);
    ListNode z(6);
    h3.next = &z;

    vector<ListNode *> v = {&h1, &h2, &h3};
    Solution solu;
    solu.mergeKLists(v);
    return 0;
}
