#include <unordered_set>
using namespace std;
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
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (head == NULL) {
            return false;
        }
        
        ListNode* slow = head;
        ListNode* fast = head;
        
        while (fast->next != NULL && fast->next->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) {
                return true;
            }
        }
        
        return false;
    }
};

// easy, but using 2 pointers, one twice as fast, is much better 
// bool hasCycle(ListNode *head) {
//     unordered_set<ListNode *> node_set;
//     while (head) {
//         if (node_set.find(head) != node_set.end()) {
//             return true;
//         }
//         node_set.insert(head);
//         head = head->next;
//     }
//     return false;
// }

int main () {
    Solution sol;
    ListNode *head = new ListNode(1);
    sol.hasCycle(head);
}