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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int m = 0;
        ListNode *tmp = head;
        while (head) {
            m++;
            head = head->next;
        }
        head = tmp;
        if (m == n) {
            return head->next;
        }
        ListNode *prev = nullptr;
        for (int i = 0; i < m - n; i++) {
            prev = head;
            head = head->next;
        }
        prev->next = head->next;
        return tmp;
    }
};

int main(int argc, char *argv[]) {
    return 0;
}
