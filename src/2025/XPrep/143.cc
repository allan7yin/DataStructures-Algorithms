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

ListNode *reverse(ListNode *head) {
    ListNode *prev = nullptr;
    while (head) {
        auto next = head->next;
        head->next = prev;
        prev = head;
        head = next;
    }

    return prev;
}

class Solution {
  public:
    void reorderList(ListNode *head) {
        if (!head || !head->next) return;

        ListNode *slow = head;
        ListNode *fast = head;
        ListNode *prev = nullptr;

        while (fast && fast->next) {
            prev = slow;
            fast = fast->next->next;
            slow = slow->next;
        }

        prev->next = nullptr;
        ListNode *second = reverse(slow);

        auto first = head;
        while (first && second) {
            auto next1 = first->next;
            auto next2 = second->next;

            first->next = second;
            if (next1) second->next = next1;

            first = next1;
            second = next2;
        }
    }
};

// first: 1 2
// second 5 4 3