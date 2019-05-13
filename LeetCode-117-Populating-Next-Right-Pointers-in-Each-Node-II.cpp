#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() {}

    Node(int _val, Node* _left, Node* _right, Node* _next) {
        val = _val;
        left = _left;
        right = _right;
        next = _next;
    }
};

class Solution {
    // Iterative method using queue;
public:
    Node* connect(Node* root) {
        queue<Node*> Q({root});
        while(!Q.empty()) {
            int size = Q.size();
            Node* currlevel = new Node(0, NULL, NULL, NULL);
            Node* curr = currlevel;
            while(size-- > 0){
                auto currnode = Q.front();
                Q.pop();
                if(currnode == NULL) continue;
                curr->next = currnode;
                curr = curr->next;

                Q.push(curr->left);
                Q.push(curr->right);
            }
            curr->next = NULL;
        }
        return root;
    }
};

