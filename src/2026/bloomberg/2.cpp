struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
  public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        ListNode *dummy = new ListNode();
        auto curr = dummy;
        int carry = 0;
        while (l1 || l2) {
            int val = carry;
            if (l1) val += l1->val;
            if (l2) val += l2->val;
            carry = val / 10;
            int digit = val % 10;

            curr->next = new ListNode(digit);
            curr = curr->next;
            if (l1) l1 = l1->next;
            if (l2) l2 = l2->next;
        }

        if (carry != 0) curr->next = new ListNode(1);

        return dummy->next;
    }
};