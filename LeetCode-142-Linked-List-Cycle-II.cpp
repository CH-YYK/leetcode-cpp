#include <iostream>
#include <unordered_map>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(!head || !head->next) return NULL;
        unordered_map<ListNode*, bool> map;
        while(head) {
            if(map.count(head)) return head;
            map[head] = true;
            head = head->next;
        }
        return NULL;
    }
};

class Solution2 {
    // two pointers
public:
    ListNode *detectCycle(ListNode *head) {
        if(!head || !head->next) return NULL;
        ListNode* fast; 
        ListNode* slow;
        fast = slow = head;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast) {
                slow = head;
                while(slow != fast) {
                    slow = slow->next;
                    fast = fast->next;
                }
                return slow;
            }
        }
        return NULL;
    }
};