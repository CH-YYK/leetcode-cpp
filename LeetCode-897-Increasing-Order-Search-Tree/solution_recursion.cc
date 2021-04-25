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
#include <stack>
#include <vector>
using namespace std;

class Solution {
public:
  TreeNode *increasingBST(TreeNode *root) {
    stack<TreeNode*> stk;
    vector<TreeNode*> inorder;
    stk.push(root);
    while(!stk.empty()) {
      auto curr = stk.top();
      while(curr->left) {
        auto tmp = curr->left;
        curr->left = nullptr;
        stk.push(tmp);
        curr = tmp;
      }
      stk.pop();
      if(curr->right)
        stk.push(curr->right);
      curr->right = nullptr;
      inorder.push_back(curr);
    }
    TreeNode* newroot = new TreeNode(0);
    TreeNode* curr = newroot;
    for(auto n : inorder) {
      curr->right = n;
      curr = curr->right;
    }
    return newroot;
  }
};
