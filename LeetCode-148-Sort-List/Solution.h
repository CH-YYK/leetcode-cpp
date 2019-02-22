#include "ListNode.h"

using namespace std;

class Solution {
public:
    ListNode* sortList(ListNode* head) {
        return divideList(head);
    }

    ListNode* mergeList(ListNode* h1, ListNode* h2){
        // merge two sorted list
        ListNode* newList = new ListNode(0);
        ListNode* curr = newList;

        while(h1 && h2){
            if(h1->val < h2->val) {
                curr->next = h1;
                h1 = h1->next;
            }else{
                curr->next = h2;
                h2 = h2->next;
            };
            curr = curr->next;
        }
        curr->next = h1 != NULL ? h1 : h2;
        return newList->next;
    }

    ListNode* divideList(ListNode* h) {
        if(!h || !h->next) return h;
        ListNode *pre = h;
        ListNode *mid = h;
        ListNode *cur = h;

        // find the middle node to split linked list
        while(cur && cur->next){
            pre = mid;
            mid = mid->next;
            cur = cur->next->next;
        }

        // first half: h, second half: mid
        pre->next = NULL;
        ListNode* h1 = divideList(h);
        ListNode* h2 = divideList(mid);
        return mergeList(h1, h2);
    }
};