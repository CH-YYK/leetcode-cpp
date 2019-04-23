#include <iostream>
#include <stack>
using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;

    Node() {}

    Node(int _val, Node* _prev, Node* _next, Node* _child) {
        val = _val;
        prev = _prev;
        next = _next;
        child = _child;
    }
};

class Solution {
    // pre-order traversal
public:
    Node* flatten(Node* head) {
        Node* pre = NULL;
        Node* curr = NULL;
        stack<Node*> S({head});
        while(!S.empty()) {
            curr = S.top();
            S.pop();
            if(curr == NULL) continue;
            if(pre == NULL) pre = curr;
            else {
                pre->next = curr, curr->prev = pre;
                pre->child = NULL;
                pre = pre->next;
            }
            S.push(curr->next);
            S.push(curr->child);
        }
        return head;
    }
};