#include <iostream>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        int i = 0;
        ListNode* pivot = NULL;
        ListNode* pre = NULL;
        ListNode* curr = new ListNode(0);
        curr->next = head;

        ListNode* start = new ListNode(0);
        start->next = head;

        ListNode* end = new ListNode(0);
        end->next = head;
        while(curr != NULL && i < n+1) {
            if(i < m-1) start = start->next;
            if(i >= m && i <= n) {
                if(pivot == NULL) pivot = curr;
                ListNode* tmp = curr->next;
                curr->next = pre;
                pre = curr;
                curr = tmp;
            }else curr = curr->next;
            i++;
        }
        pivot->next = curr;
        start->next = pre;
        if(m == 1) return pre;
        return head;
    }
};