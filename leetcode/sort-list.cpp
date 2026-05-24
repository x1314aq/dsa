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
    ListNode* merge(ListNode* l1, ListNode* l2) {
        if (!l1) return l2;
        if (!l2) return l1;
        ListNode *head = nullptr;
        if (l1->val < l2->val) {
            head = l1;
            l1 = l1->next;
        } else {
            head = l2;
            l2 = l2->next;
        }
        ListNode *tmp = head;
        while (l1 && l2) {
            if (l1->val < l2->val) {
                head->next = l1;
                l1 = l1->next;
            } else {
                head->next = l2;
                l2 = l2->next;
            }
            head = head->next;
        }
        head->next = !l1 ? l2 : l1;
        return tmp;
    }

    ListNode* sort(ListNode *head, int n) {
        if (n == 1) return head;
        ListNode *prev = nullptr;
        ListNode *tmp = head;
        for (int i = 0; i < n / 2; i++) {
            prev = tmp;
            tmp = tmp->next;
        }
        prev->next = nullptr;
        ListNode *l = sort(head, n / 2);
        ListNode *r = sort(tmp, n - n / 2);
        return merge(l, r);
    }

    ListNode* sortList(ListNode* head) {
        if (!head || !head->next) return head;
        int n = 0;
        ListNode *tmp = head;
        while (tmp) {
            n++;
            tmp = tmp->next;
        }
        return sort(head, n);
    }
};

int main(int argc, char *argv[]) {
    return 0;
}
