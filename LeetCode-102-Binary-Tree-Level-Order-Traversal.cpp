#include <iostream>
#include <vector>
#include <tuple>
#include <queue>
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<tuple<TreeNode*, int>> Queue({{root, 0}});
        tuple<TreeNode*, int> curr;
        vector<vector<int>> res;

        while(!Queue.empty()) {
            curr = Queue.front();
            Queue.pop();
            
            TreeNode* tmp; int level;
            tie(tmp, level) = curr;
            if(res.size() == level)
                res.push_back(vector<int>({tmp->val}));
            else
                res.back().push_back(tmp->val);
            
            if(tmp->left)
                Queue.push(tuple<TreeNode*, int>({tmp->left, level+1}));
            if(tmp->right)
                Queue.push(tuple<TreeNode*, int>({tmp->right, level+1}));
        }
        return res;   
    }
};