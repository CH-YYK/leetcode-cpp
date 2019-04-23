#include <unordered_map>
#include <vector>
#include <iostream>
#include <stack>
using namespace std;

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) {
        ListNode *curr1 = head, *curr2 = head;
        unordered_map<ListNode*, ListNode*> map;

        stack<ListNode*> S;
        while(curr1) {
            while(!S.empty() && curr1->val > S.top()->val) {
                map[S.top()] = curr1;
                S.pop();
            }
            S.push(curr1);
            curr1 = curr1->next;
        }

        vector<int> res;
        while(curr2) {
            if(map.count(curr2)) res.push_back(map[curr2]->val);
            else res.push_back(0);
        }
        return res;
    }
};


class Solution2 {
public:
    vector<int> nextLargerNodes(ListNode* head) {
        ListNode *curr1=head;
        vector<int> res;
        stack<int> S;

        int i = 0;
        while(curr1) {
            while(!S.empty() && curr1->val > res[S.top()]) {
                res[S.top()] = curr1->val;
                S.pop();
            }
            S.push(i++);
            res.push_back(curr1->val);
            curr1 = curr1->next;
        }
        while(!S.empty()) res[S.top()] = 0, S.pop();
        return res;
    }
};
