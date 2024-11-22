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
    // we just keep 2 nodes n spaces apart, and when the first one reaches the end, return the second one
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        int count = 0;
        auto s = head;
        auto dummy = new ListNode(0, head);
        ListNode *prev = nullptr;

        while (head) {
            head = head->next;
            prev = s;
            if (count >= n) s = s->next;
            count++;
        }

        if (count == n) {
            // need to delete current node
            return dummy->next->next;
        } else {
            prev->next = s->next;
        }

        return dummy->next;
    }
};