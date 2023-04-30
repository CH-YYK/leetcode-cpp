// method of brute force, O(Nk*log(Nk)) in time, O(Nk) in space.
#include <vector>
#include <iostream>
#include "ListNode.h"

using namespace std;

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {

        // jump out if 'lists' is empty
        if(lists.empty()) return NULL;

        // create vector to store all node values
        vector<int> nodes;
        for(ListNode* cur:lists){
            while(cur != NULL){
                nodes.push_back(cur->val);
                cur = cur->next;
            }
        }

        // sorting the node values
        sort(nodes.begin(), nodes.end());

        // create new listNode along with a iterator
        ListNode *newList = new ListNode(0);
        ListNode *curr = newList;
        for(int i:nodes){
            curr->next = new ListNode(i);
            curr = curr->next;
        }
        return curr;
    }
};
