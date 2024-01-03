struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // create 2 pointers n apart from each other 
        // when second pointer reaches the end, first one is is at nth from end, remove it
        ListNode *l = head;
        ListNode *r = head;
        for (int i = 0; i < n; i++) {
            r = r->next;
        }

        if (r == nullptr) {
            return head->next;
        }

        while (r->next) {
            r = r->next;
            l = l->next;
        }

        // remove 
        l->next = l->next->next;
        return head;
    }
};

int main() {}