#include <iostream>
#include <vector>
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
    int maxPathSum(TreeNode* root) {
        int sum_all = dfs(root);
        return max(sum_all, maxmum);
    }

private:
    int maxmum = INT_MIN;

    int dfs(TreeNode* root) {
        if(root == NULL) return 0;
        
        int leftsum = max(dfs(root->left), 0);
        int rightsum = max(dfs(root->right), 0);

        maxmum = max(maxmum, leftsum + rightsum + root->val);
        return max(leftsum, rightsum) + root->val;
    }
};