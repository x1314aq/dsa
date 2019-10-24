/**
 * Leetcode 430 Flatten a Multilevel Doubly Linked List
 * DFS
 */

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;

    Node() {}

    Node(int _val, Node* _prev, Node* _next, Node* _child) {
        val = _val;
        prev = _prev;
        next = _next;
        child = _child;
    }
};

class Solution {
public:
    Node* flatten(Node* head) {
        if(!head) return NULL;
        dfs(NULL, head);
        return head;
    }

    Node *dfs(Node *parent, Node *child) {
        child->prev = parent;
        if(parent) {
            parent->next = child;
            parent->child = NULL;
        }

        while(child) {
            Node *n = child->next;
            if(child->child) {
                Node *tail = dfs(child, child->child);
                tail->next = n;
                if(n) n->prev = tail;
                parent = tail;
            }
            else parent = child;
            child = n;
        }
        return parent;
    }
};

int main() {
    Node arrs[700];
    for(int i = 0; i < 700; i++) {
        arrs[i].val = i;
        arrs[i].next = NULL;
        arrs[i].prev = NULL;
        if(i < 699) arrs[i].child = arrs + i + 1;
        else arrs[i].child = NULL;
    }
    Solution s;
    Node *head = s.flatten(arrs);
    while(head) {
        cout << head->val << endl;
        head = head->next;
    }
    return 0;
}
