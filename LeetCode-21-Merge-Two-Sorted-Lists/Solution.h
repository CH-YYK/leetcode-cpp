#include <iostream>
#include <vector>
#include "ListNode.h"

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode newList(0);
        ListNode* curr = &newList;
        while(l1 != NULL || l2 != NULL){
            if(l1 != NULL && l2 != NULL){
                if(l1->val < l2->val){
                    curr->next = l1;
                    l1 = l1->next;
                }else{
                    curr->next = l2;
                    l2 = l2->next;
                }
                curr = curr->next;
            }else{
                if(l1) curr->next = l1;
                else curr->next = l2;
                break;
            }
        }
        return newList.next;
    }
};