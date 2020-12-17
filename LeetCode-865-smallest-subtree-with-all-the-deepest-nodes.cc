#include <vector>

// Definition for a binary tree node.
#include <utility>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
  TreeNode* subtreeWithAllDeepest(TreeNode* root) {
    result = root;
    _distance = 0;
    pair<TreeNode*, int> res = dfs(0, root);
    return res.first;
  }
private:
  TreeNode* result;
  int _distance;
  pair<TreeNode*, int> dfs(int depth, TreeNode* node) {
    if(node == NULL) return {NULL, depth};
    
    pair<TreeNode*, int> left = dfs(depth+1, node->left);
    pair<TreeNode*, int> right = dfs(depth+1, node->right);
    
    if(left.second == right.second) 
      return {node, left.second};
    else if(left.second > right.second) 
      return left;
    else if(left.second < right.second)
      return right;
  }
};