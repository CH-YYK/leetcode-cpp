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
public:
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*> S;
        S.push(root);

        int ind = 1;
        while(!S.empty()) {
            TreeNode* curr = S.top();
            S.pop();
            if(curr == NULL) continue;
            while(curr->left) {
                TreeNode* tmp = curr->left;
                curr->left = NULL;
                S.push(curr);
                curr = tmp;
            }
            if(ind++ == k) return curr->val;
            S.push(curr->right);            
        }
        return 0;
    }
};