#include <stack>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
                                                     right(right) {}
};

/* In-order traverse the tree until kth element found
 * an in-order traverse of a BST is ascending 
 */
class Solution {
public:
  int kthSmallest(TreeNode *root, int k) {
    TreeNode *_tmp = NULL, *_curr = NULL;
    stack<TreeNode *> _stack;
    _stack.push(root);
    while (!_stack.empty()) {
      _curr = _stack.top();
      _stack.pop();

      // Find the leftmost value from the current root
      while (_curr->left) {
        _tmp = _curr->left;
        _curr->left = NULL;
        _stack.push(_curr);
        _curr = _tmp;
      }

      // '_curr' is the next leftmost(minimum) value
      // '_curr' is outside the _stack
      if (--k == 0)
        return _curr->val;
      if (_curr->right)
        _stack.push(_curr->right);
    }
    return 0;
  }
};
