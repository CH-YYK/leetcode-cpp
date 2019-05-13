#include <iostream>
#include <vector>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        if(head == NULL) return NULL;

        ListNode* pre = NULL;
        ListNode* curr = head;
        ListNode* fast = head;

        int i = 0;

        while(fast->next != NULL) {
            if(i++ % 2 == 0 && i > 0) {
                pre = pre == NULL ? curr : pre->next;
                curr = curr->next;
            }
            fast = fast->next;
        }

        if(pre != NULL) {
            pre->next = NULL;
            pre = head;
        }
    
        TreeNode* root = new TreeNode(curr->val);
        root->left = sortedListToBST(pre);
        root->right = sortedListToBST(curr->next);
        return root;
    }    
};