#include <iostream>
#include <stack>
#include <limits.h>
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
    int minDiffInBST(TreeNode* root) {
                TreeNode* pre = NULL;
        TreeNode* curr = NULL;

        int min = INT_MAX;

        // create stack to store values in ascending order
        stack<TreeNode*> s({root});
        while(!s.empty()) {
            curr = s.top();
            s.pop();
            if(curr == NULL) continue;
            while(curr->left) {
                TreeNode* tmp = curr->left;
                curr->left = NULL;
                s.push(curr);
                curr = tmp;
            }
            s.push(curr->right);
            if(pre != NULL) {
                min = abs(curr->val - pre->val) < min ? abs(curr->val - pre->val) : min;
            }
            pre = curr;
        }
        return min;
    }
};