// Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

/*

1 2 3 4
4 3 2 1


1 -> 4 -> 2
*/
class Solution {
private:
  int length = 0;

public:
  ListNode *reverseList(ListNode *head) {
    ListNode *prev = nullptr;
    while (head) {
      auto cur = new ListNode(head->val, prev);
      length++;
      prev = cur;
      head = head->next;
    }
    return prev;
  }
  void reorderList(ListNode *head) {
    // first make a reverse copy
    ListNode *rev = reverseList(head);

    // we have the length of the LL in class variable
    ListNode *dummy = new ListNode();
    dummy->next = head;
    for (int i = 0; i < length / 2; i++) {
      auto n1 = head->next;
      auto n2 = rev->next;

      head->next = rev;
      rev->next = n1;
      head = n1;
      rev = n2;

      if (i == (length / 2) - 1) {
        head->next = nullptr;
        rev->next = nullptr;
      }
    }

    head = dummy->next;
  }
};
