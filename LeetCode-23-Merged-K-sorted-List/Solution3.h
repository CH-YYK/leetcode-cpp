// Method by using priority queue, O(N*k*log(k)) in time and O(k) in space
#include <iostream>
#include <vector>
#include <queue>
#include "ListNode.h"

using namespace std;

struct orderNodes {
    bool operator()(const ListNode* l1, const ListNode* l2){
        return l1->val > l2->val;
    }
};

class Solution3 {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists){
        // jump out if 'lists' is NULL
        if(lists.empty()) return NULL;
        ListNode *newList = new ListNode(0);
        ListNode* curr = newList;

        // define priority queue and initialize by the first batch of head values
        priority_queue<ListNode*, vector<ListNode*>, orderNodes> heap;
        for(ListNode* head:lists){
            if(head) heap.push(head);
        }

        // popping and pushing (if the next node is valid)
        while(!heap.empty()){
            curr->next = heap.top();
            heap.pop();
            curr = curr->next;
            if(curr->next) heap.push(curr->next);
        }

        return newList->next;
    }
};