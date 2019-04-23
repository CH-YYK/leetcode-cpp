#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namesapce std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        queue<TreeNode*> Q({root});
        int levels = 0;
        
        while(!Q.empty()) {
            vector<TreeNode*> vec;
            while(!Q.empty()) {
                if(Q.front() != NULL) vec.push_back(Q.front());
                Q.pop();
            }

            vector<int> sub_res;
            for(auto &i : vec){
                sub_res.push_back(i->val);
                Q.push(i->left), Q.push(i->right);
            }
            if(levels++ % 2 == 0) reverse(sub_res.begin(), sub_res.end());
            if(!sub_res.empty()) res.push_back(sub_res);
        }
        return res;
    }
};