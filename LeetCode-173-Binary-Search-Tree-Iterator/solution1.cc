#include <stack>
using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */

// in-order traversal
class BSTIterator {
public:
  BSTIterator(TreeNode *root) {
    s.push(root);
  }

  int next() {
    TreeNode *tmp;
    while (!s.empty()) {
      TreeNode *curr = s.top();
      s.pop();
      while (curr->left) {
        tmp = curr->left;
        curr->left = nullptr;
        s.push(curr);
        curr = tmp;
      }

      if (curr->right)
        s.push(curr->right);
      return curr->val;
    }
    return 0;
  }

  bool hasNext() {
    return !s.empty();
  }
private:
  stack<TreeNode*> s;
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
