#include <vector>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

// we'll maintain 2 indices -> one for the left index and one for the right
// indedx
class Solution {
public:
  TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
    int place = 0;
    return build(preorder, inorder, place, 0, inorder.size() - 1);
  }

  TreeNode *build(vector<int> &preorder, vector<int> &inorder, int &place,
                  int index1, int index2) {
    if (index2 < index1) {
      return nullptr;
    }
    TreeNode *head = new TreeNode(preorder[place]);
    int split = 0;
    for (int i = 0; i < inorder.size(); i++) {
      if (inorder[i] == preorder[place]) {
        split = i;
        break;
      }
    }
    place++;
    head->left = build(preorder, inorder, place, index1, split - 1);
    head->right = build(preorder, inorder, place, split + 1, index2);

    return head;
  }
};
