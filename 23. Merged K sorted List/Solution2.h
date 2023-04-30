// method by minimizing, O(Nk^2) in time, O(1) in space
#include <iostream>
#include <vector>
#include "ListNode.h"

using namespace std;

class Solution2 {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists){
        if(lists.empty()) return NULL;
        ListNode *newList = new ListNode(0);
        ListNode *curr = newList;

        do{
            int head_idx=-1, head_val=INT_MAX;
            for(int i = 0; i < lists.size(); i++){
                if(lists[i] && lists[i]->val < head_val){
                    head_idx = i;
                    head_val = lists[i]->val;
                }
            }
            if(head_idx == -1) break;
            curr->next = lists[head_idx];
            curr = curr->next;
            lists[head_idx] = curr->next;
        }while(true);

        return newList->next;
    }
};