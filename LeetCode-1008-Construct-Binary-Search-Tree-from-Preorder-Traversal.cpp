#include <vector>
#include <stack>
#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        // if(preorder.empty()) return NULL;
        stack<TreeNode*> roots;
        TreeNode* root = new TreeNode(preorder[0]);
        roots.push(root);
        
        for(int j =1; j<preorder.size() ; j++) {
            TreeNode* curr = roots.top();
            int i = preorder[j];
            if(curr->val > i) {
                curr->left = new TreeNode(i);
                roots.push(curr->left);
                continue;
            }
            
            while(!roots.empty() && roots.top()->val < i) {
                curr = roots.top(); 
                roots.pop();
            }
            curr->right = new TreeNode(i);
            roots.push(curr->right);
        }
        return root;
    }
};

int main() {
    vector<int> preorder = {8, 5, 1, 7 ,10 ,12};
    auto ans = Solution().bstFromPreorder(preorder);
    cout << ans << endl;
}