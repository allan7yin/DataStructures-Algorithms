// Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
  ListNode *middleNode(ListNode *head) {
    ListNode *tortoise = head;
    ListNode *hare = head;

    while (hare && hare->next) {
      hare = hare->next->next;
      tortoise = tortoise->next;
    }
    return tortoise;
  }
};
