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
    void reorderList(ListNode* head) {
        ListNode* quick = head;
        ListNode* slow = head;
        ListNode* pre = NULL;

        int i = 0;
        while(quick) {
            if(i++ % 2 != 0) slow = slow->next;
            quick = quick->next;
        }

        while(slow) {
            ListNode* tmp = slow->next;
            slow->next = pre;
            pre = slow;
            slow = tmp;
        }

        while(pre != head && head && pre->next) {
            ListNode* tmp = head->next;
            ListNode* tmp2 = pre->next;
            head->next = pre;
            pre->next = tmp;
            pre = tmp2;
            head = tmp;
        }
    }
};git 