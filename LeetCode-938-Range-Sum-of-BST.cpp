#include <iostream>
#include <stack>
using namespace std;

//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
    // in-order traversal will be in ascending order
public:
    int rangeSumBST(TreeNode* root, int L, int R) {
        int sum = 0;
        TreeNode* curr = NULL;
        TreeNode* tmp = NULL;
        stack<TreeNode*> s({root});
        while(!s.empty()) {
            curr = s.top();
            s.pop();
            if(curr == NULL) continue;
            while(curr->val < L && curr->right != NULL) {
                curr = curr->right;
            }
            while(curr->val > L && curr->left != NULL) {
                tmp = curr->left;
                curr->left = NULL;
                s.push(curr);
                curr = tmp;
            }
            if(curr->val >= L) sum += curr->val;
            if(curr->val == R) break;
            s.push(curr->right);
        }
        return sum;
    }
};