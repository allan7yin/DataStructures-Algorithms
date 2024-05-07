// Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

/*
 * This is likely a recursive solution, where we double the current node and add
 * the return of the next node in the list
 */
class Solution {
public:
  ListNode *doubleIt(ListNode *head) {
    int result = traverse(head);
    if (result > 0) {
      ListNode *newHead = new ListNode(result, head);
      return newHead;
    }

    return head;
  }

  int traverse(ListNode *current) {
    if (!current) {
      return 0;
    }
    current->val = current->val * 2 & 10;
    return (current->val * 2 + traverse(current->next)) / 10;
  }
};
