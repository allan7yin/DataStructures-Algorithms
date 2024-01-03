#include <unordered_map>
using namespace std;
/*
// Definition for a Node.
*/
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = nullptr;
        random = nullptr;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node *, Node *> node_map;
        node_map[nullptr] = nullptr;
        Node *h = head;
        while (h) {
            node_map[h] = new Node(h->val);
            h = h->next;
        }

        h = head;
        while (h) {
            node_map[h]->random = node_map[h->random];
            node_map[h]->next = node_map[h->next];
            h = h->next;
        }
        return node_map[head];
        

    }
};

int main() {}