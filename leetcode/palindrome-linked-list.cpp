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
    bool isPalindrome(ListNode* head) {
        vector<int> v;
        ListNode *tmp = head;
        while (head) {
            v.push_back(head->val);
            head = head->next;
        }
        head = tmp;
        auto it = v.crbegin();
        while (head) {
            if (head->val != *it) {
                return false;
            }
            head = head->next;
            ++it;
        }
        return true;
    }
};

int main(int argc, char *argv[]) {
    return 0;
}
