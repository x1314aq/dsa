using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        unordered_set<ListNode *> us;
        while (head) {
            if (us.find(head) != us.end()) {
                return head;
            }
            us.insert(head);
            head = head->next;
        }
        return nullptr;
    }
};

int main(int argc, char *argv[]) {
    return 0;
}
