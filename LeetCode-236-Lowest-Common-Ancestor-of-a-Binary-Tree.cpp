#include <iostream>

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        dfs(root, p, q);
        return ans;
    }

private:
    TreeNode* ans;
    bool dfs(TreeNode* root, TreeNode* p, TreeNode* q){
        if(root == NULL) return false;
        bool left = dfs(root->left, p, q);
        bool right = dfs(root->right, p, q);
        if(root->val == p->val || root->val == q->val){
            if(left || right) {
                ans = root;
                return true;
            } else{
                return true;
            }
        }
        else if(left && right){
            ans = root;
            return left && right;
        }
        return left || right;
    }
};