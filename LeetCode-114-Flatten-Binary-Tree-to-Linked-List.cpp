#include <iostream>
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
    // pre-order traversal
    // O(N) in time, O(1) in space
public:
    void flatten(TreeNode* root) {
        stack<TreeNode*> S({root});
        TreeNode* pre = NULL, *curr = NULL;
        while(!S.empty()) {
            curr = S.top();
            S.pop();
            if(curr == NULL) continue;
            if(pre == NULL) pre = curr;
            else{
                pre->left = NULL;
                pre->right = curr;
                pre = pre->right;
            }
            S.push(curr->right);
            S.push(curr->left);
        }
    }
};