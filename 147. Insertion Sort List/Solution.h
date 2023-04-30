#include "ListNode.h"

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        if(!head) return head;

        auto *newList = new ListNode(-INT_MAX);
        ListNode *curr = newList;
        while(head){
            if(head->val > curr->val){
                curr->next = head;
                head = head->next;
                curr = curr->next;
                curr->next = NULL;
            }else{
                ListNode *tmpNode = newList;
                while(tmpNode->next && tmpNode->next->val < head->val)
                    tmpNode = tmpNode->next;
                ListNode *tmp = tmpNode->next;
                tmpNode->next = head;
                head = head->next;
                tmpNode->next->next = tmp;
            }
        }
        return newList->next;
    }
};