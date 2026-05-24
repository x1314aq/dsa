using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode *recursion(ListNode *head) {
        if (!head || !head->next) return head;

        ListNode *a = head;
        ListNode *b = head->next;
        ListNode *c = b->next;
        b->next = a;
        a->next = recursion(c);
        return b;
    }

    ListNode* swapPairs(ListNode* head) {
        return recursion(head);
    }
};

int main(int argc, char *argv[]) {
    return 0;
}
