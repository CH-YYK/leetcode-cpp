#include <iostream>
#include <vector>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL || k == 0) return head;
        
        int n = 0;
        ListNode* curr = head;
        while(curr) curr = curr->next, n++;

        k %= n;
        ListNode* pre = head;
        ListNode* newcurr = head;

        int i = 0;
        while(newcurr->next) {
            if(i++ >= k) pre = pre->next;
            newcurr = newcurr->next;     
        }
        
        newcurr->next = head;
        ListNode* res = pre->next;
        pre->next = NULL;
        return res;
    }   
};