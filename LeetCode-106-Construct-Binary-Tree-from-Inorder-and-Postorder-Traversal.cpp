#include <iostream>
#include <vector>
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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return recurhelper(inorder, postorder, 0, inorder.size()-1);
    }
private:
    TreeNode* recurhelper(vector<int>& inorder, vector<int>& postorder, int i, int j) {
        if(i > j) return NULL;
        TreeNode* root = new TreeNode(postorder.back());
        int pivot = 0;
        for(int i = 0; i < inorder.size() && inorder[pivot] != root->val; i++) pivot++;
        postorder.pop_back();
        
        root->right = recurhelper(inorder, postorder, pivot+1, j);
        root->left = recurhelper(inorder, postorder, i, pivot-1);
        return root;
    }
};