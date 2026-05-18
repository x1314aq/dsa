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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *ans = new ListNode();

        int carry = 0;
        ListNode *last = ans;
        while (l1 && l2) {
            int sum = l1->val + l2->val + carry;
            carry = sum / 10;
            sum %= 10;
            ListNode *cur = new ListNode(sum);
            last->next = cur;
            last = cur;
            l1 = l1->next;
            l2 = l2->next;
        }

        while (l1) {
            int sum = l1->val + carry;
            carry = sum / 10;
            sum %= 10;
            ListNode *cur = new ListNode(sum);
            last->next = cur;
            last = cur;
            l1 = l1->next;
        }

        while (l2) {
            int sum = l2->val + carry;
            carry = sum / 10;
            sum %= 10;
            ListNode *cur = new ListNode(sum);
            last->next = cur;
            last = cur;
            l2 = l2->next;
        }

        if (carry) {
            ListNode *cur = new ListNode(carry);
            last->next = cur;
        }

        ListNode *output = ans->next;
        delete ans;

        return output;
    }
};

int main(int argc, char *argv[]) {
    return 0;
}
