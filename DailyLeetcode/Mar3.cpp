// Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:
  ListNode *removeNthFromEnd(ListNode *head, int n) {
    // move 2 pointers, n steps apart
    ListNode *prev = nullptr;
    ListNode *l1 = head;
    ListNode *l2 = head;
    int count = 0;
    while (l1) {
      if (count == n) {
        prev = l2;
        l2 = l2->next;
        l1 = l1->next;
      } else {
        count++;
        l1 = l1->next;
      }
    }

    // remove the node at l2
    if (!prev) {
      return head->next;
    } else {
      prev->next = l2->next;
      delete l2;
      return head;
    }
  }
};
