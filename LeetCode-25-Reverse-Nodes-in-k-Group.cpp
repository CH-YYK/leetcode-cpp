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
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        int n = 0;
        ListNode* curr = head;
        while(curr) n++, curr = curr->next;
        return partition(head, n, k);
    }
private:
    ListNode* partition(ListNode* head, int n, int k) {
        if(n < k) return head;
        int i = 0;
        ListNode* curr = head;
        ListNode* pre = NULL;
        while(i++ < k && curr) {
            ListNode* tmp = curr->next;
            curr->next = pre;
            pre = curr;
            curr = tmp;
        }
        pre->next = partition(curr, n - k, k);
        return pre;
    }
};