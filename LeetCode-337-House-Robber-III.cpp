#include <iostream>
#include <unordered_map>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    int rob(TreeNode* root) {
        if(root == NULL) return 0;
        if(memo.count(root)) return memo[root];
        int max1 = root->val;
        int max2 = rob(root->left) + rob(root->right);
        if(root->left != NULL)
            max1 += (rob(root->left->left) + rob(root->left->right));
        if(root->right != NULL)
            max1 += (rob(root->right->left) + rob(root->right->right));
        memo[root] = max(max1, max2);
        return memo[root];
    };
private:
    unordered_map<TreeNode*, int> memo;
};