
/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode();
        int carryover = 0;
        ListNode* sum = dummy;
        while (l1 || l2) {
            int val1 = (l1 ? l1->val: 0);
            int val2 = (l2 ? l2->val: 0);
            int value = val1 + val2;
            sum->next = new ListNode((carryover + value)%10);
            carryover = (carryover + value) / 10;
            sum = sum->next;
            if (l1) {
                l1 = l1->next;
            }
            if (l2) {
                l2 = l2->next;    
            }
        }

        if (carryover > 0) {
            sum->next = new ListNode(carryover);
        }
        return dummy->next;
    }
};

int main() {}