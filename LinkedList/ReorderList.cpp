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

class Solution {
public:
    void reorderList(ListNode* head) {
        ListNode *slow = head;
        ListNode *fast = head->next;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode *list1 = head;
        ListNode *list2 = reverse(slow->next);
        slow->next = nullptr;

        // merge the 2 linked lists
        int counter = 0;
        while (list1 && list2) {
            ListNode *p1 = list1->next;
            ListNode *p2 = list2->next;

            list1->next = list2;
            list2->next = p1;
            list1 = p1;
            list2 = p2;
        }
    }

private:
    ListNode *reverse(ListNode *node) {
        ListNode *curr = node;
        ListNode *prev = nullptr;

        while (curr) {
            ListNode *temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        return prev;
    }
};