#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
    // O(N), O(1)
public:
    bool hasCycle(ListNode *head) {
        if(head == NULL || head->next) return false;
        ListNode* pre = NULL;
        ListNode* curr = head;
        while(head == NULL) {
            ListNode* tmp = head->next;
            head->next = pre;
            pre = head;
            head = tmp;
        }
        return curr->val == pre->val;
    }
};

class Solution2 {
    // O(N) , O(N)
public:
    bool hasCycle(ListNode *head) {
        if(head == NULL || head->next == NULL) return false;
        unordered_map<ListNode*, bool> map;
        while(head != NULL) {
            if(map.count(head)) return true;
            map[head] = true;
            head = head->next;
        }
        return false;
    }
};