#include <iostream>
using namespace std;

//Definition for singly-linked list.
struct ListNode {
   int val;
   ListNode *next;
   ListNode(int x) : val(x), next(NULL) {}
 };
 
class Solution {
    // setup two pointers with step gap
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* fast = head;
        ListNode* newList = new ListNode(0);
        ListNode* pre = newList;
        ListNode* slow = head;

        pre->next = head;
        int i = 0;
        while(fast->next != NULL) {
            if(i >= n-1) {
                slow = slow->next;
                pre = pre->next;
            }
            fast = fast->next;
            i++;
        }
        pre->next = slow->next;
        return newList->next;
    }
};