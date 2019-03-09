#include <iostream>
#include <numeric>
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
    // iteratively in-order traversal
public:
    bool isValidBST(TreeNode* root) {
        if(root == NULL) return true;
        stack<TreeNode*>Stack({root});
        TreeNode* pre = NULL;
        while(!Stack.empty()){
            TreeNode* curr = Stack.top();
            Stack.pop();
            if(curr == NULL) continue;
            while(curr->left){
                TreeNode* tmp = curr->left;
                curr->left = NULL;
                Stack.push(curr);
                curr = tmp;
            }
            if(pre != NULL){
                if(pre->val >= curr->val) return false;
                pre = curr;
            } else pre = curr;

            if(curr->right){
                Stack.push(curr->right);
            }
        }
        return true;
    }
};