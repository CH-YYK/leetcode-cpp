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
    // Idea: loop over the list, keep removind node that has even index and adding it to the tail
    // Loop 1: get the tail node
    // Loop 2: removing and appending
    
    // corner cases.
    // 0-element: return NULL
    // 1-element: do nothing
    // 2-element: do not need to remove the 2nd node
    // >2-element: remove and add

    // O(N) O(1)
public:
    ListNode* oddEvenList(ListNode* head) {
        if(head == NULL) return head;
        ListNode* end = head;
        while(end->next) {
            end = end->next;
        }

        int ind = 1;
        ListNode* newNode = new ListNode(0);
        newNode->next = head;
        ListNode* pre = newNode;
        ListNode* tail = end;
        
        while(pre && pre->next) {
            ListNode* cur = pre->next;
            if(cur->next == NULL) break;
            if(ind++ % 2 == 0) { 
                pre->next = cur->next;
                cur->next = NULL;
                tail->next = cur;
                tail = tail->next;
            }else pre = cur;
            if(cur == end) break;
        }
        return newNode->next;
    }
};

int main() {
    vector<int> vec = {1,2,3,4,5};
    ListNode* head = new ListNode(0);
    ListNode* cur = head;
    for(auto i : vec) {
        cur->next = new ListNode(i);
        cur = cur->next;
    }
    head = head->next;

    ListNode* ans = Solution().oddEvenList(head);
}