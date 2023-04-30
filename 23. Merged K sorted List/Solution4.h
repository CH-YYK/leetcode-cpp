#include <algorithm>
#include <iostream>
#include <vector>
#include "ListNode.h"

using namespace std;

static bool heapOrder(const ListNode* l1, const ListNode* l2){
    return l1->val > l2->val;
}

class Solution4 {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists){
        if(lists.empty()) return NULL;

        ListNode newList(0), *curr = &newList;
        vector<ListNode*> heap;
        for(ListNode* head:lists){
            if(head)
                heap.push_back(head);
        }

        make_heap(heap.begin(), heap.end(), heapOrder);

        while(!heap.empty()){
            curr->next = heap.front();
            pop_heap(heap.begin(), heap.end(), heapOrder);
            heap.pop_back();
            if(curr->next->next) {
                heap.push_back(curr->next->next);
                push_heap(heap.begin(), heap.end(), heapOrder);
            }
            curr = curr->next;
        }
        return newList.next;
    }
};