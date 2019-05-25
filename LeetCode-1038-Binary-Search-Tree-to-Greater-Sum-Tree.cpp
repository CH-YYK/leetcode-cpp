#include <iostream>
#include <vector>
#include <stack>
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
    int pre = 0;
    TreeNode* bstToGst(TreeNode* root) {
        if(root->right) bstToGst(root->right);
        root->val += pre;
        pre = root->val;
        if(root->left) bstToGst(root->left);
        return root;
    }
};

