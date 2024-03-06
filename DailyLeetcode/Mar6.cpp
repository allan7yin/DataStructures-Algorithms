// Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(nullptr) {}
};

// try the tortoise and hare approach -> one pointer traverses twice the speed
class Solution {
public:
  bool hasCycle(ListNode *head) {
    if (head == nullptr) {
      return false;
    }
    ListNode *tortoise = head;
    ListNode *hare = head->next;

    while (tortoise != hare) {
      if (tortoise == nullptr || hare == nullptr || hare->next == nullptr) {
        return false;
      }
      tortoise = tortoise->next;
      hare = hare->next->next;
    }
    return true;
  }
};
