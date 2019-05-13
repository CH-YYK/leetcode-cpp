#include <stack>
#include <string>
#include <iostream>
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
    TreeNode* recoverFromPreorder(string S) {
        S += '-';
        stack<pair<TreeNode*, int>> Stack;
        pair<TreeNode*, int> root;
        int depth = 0;
        string num;
        for(char c : S) {
            if(isdigit(c)){
                num += c;
                continue;
            }

            if(c == '-' && num == ""){
                depth++;
                continue;
            }

            TreeNode* curr = new TreeNode(stoi(num));
            pair<TreeNode*, int> currpair = {curr, depth-1};
            if(Stack.empty()) {
                Stack.push(currpair);
                root = currpair;
            }else{
                while(!Stack.empty()) {
                    auto prepair = Stack.top();
                    if(prepair.first->left != NULL && prepair.first->right != NULL) 
                        Stack.pop();
                    else if(currpair.second == prepair.second) 
                        Stack.pop();
                    else if(currpair.second == prepair.second + 1){
                        if(prepair.first->left) prepair.first->right = currpair.first;
                        else prepair.first->left = currpair.first;
                        break;
                    }else Stack.pop();
                }
            }
            Stack.push(currpair);
            num = "";
            depth = 1;
        }
        return root.first;
    }
};