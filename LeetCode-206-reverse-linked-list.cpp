#include <iostream>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
 };
 
class Solution {
    // Iterative solution
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* pre = NULL;
        while(head != NULL) {
            ListNode* tmp = head->next;
            head->next = pre;
            pre = head;
            head = tmp;
        }
        return pre;       
    }
};

class Solution2 {
    // recursive solution
public:
    ListNode* reverseList(ListNode* head) {
        recur(head);
        return pre;
    };

private:
    ListNode* pre = NULL;
    ListNode* tmp = NULL;

    void recur(ListNode* curr) {
        if(curr == NULL) return ;
        tmp = curr->next;
        curr->next = pre;
        pre = curr;
        recur(tmp);    
    }
};
